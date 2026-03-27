经过上一个工程，完成LVGL移植以及DMA2D的编写后，我们这边需要进行将屏幕翻转。
难点：lv_port_disp 的设置， 
需要知道的是，此款芯片ST7701s，屏幕为左边切割屏，通过咨询厂家，这个spi初始化屏幕，只能够上下进行翻转，不能够左右进行翻转  
SPI_WriteComm (0x36);
SPI_WriteData (0x10); 上下反转

而我们需要90度翻转，可以知道 通过物理翻转已经不可行，我们只能够通过软件进行翻转。
思考：能不能通过  ltdc_color_fill(area->x1, area->y1, area->x2, area->y2, &color_p->full);更改X\Y  将其调转进行实现？
结果，这个ltdc_color_fill 是DMA2D 是写在SDRAM上的，是通过写在SDRAM数据，不能通过这个进行翻转

我们只能使用    
disp_drv.sw_rotate = 1;
    disp_drv.rotated = LV_DISP_ROT_90;
    这个函数进行翻转。
    ，然后我们在此之前，需要打开LVGL的时钟LV_MEM_CUSTOM 1  不然画面是不会动的
    这里我们将dma2d 的程序进行了优化，加上了互斥锁
    osThreadId_t drawingTaskHandle = NULL; // 记录当前是谁在用 DMA2D

/* 1. 定义互斥量句柄 */
osMutexId_t dma2dMutexHandle;
/* 3. 在初始化函数中创建互斥量  */
void DMA2D_Mutex_Init(void) {
    const osMutexAttr_t Thread_Mutex_attr = {
        "dma2dMutex",                          // 名字
        osMutexRecursive| osMutexPrioInherit, 
        NULL, 0
    };
    dma2dMutexHandle = osMutexNew(&Thread_Mutex_attr);
}

/**
 * @brief  DMA2D 纯色填充函数 (R2M 模式)
 * @param  sx, sy: 起始坐标
 * @param  ex, ey: 结束坐标
 * @param  color:  填充的颜色 (RGB565格式)
 */
void ltdc_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint32_t color)
{
    // 1. 抢占互斥锁 (Mutex)
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;

    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint16_t offline = 240 - width; // 屏幕宽度减去填充宽度
    uint32_t addr = 0xD0000000 + 2 * (240 * sy + sx); // 目标显存地址
    /* 记录当前正在调用的任务 ID */
    drawingTaskHandle = osThreadGetId();    
    
    DMA2D->CR = DMA2D_R2M; 
    DMA2D->OCOLR = color; 
    DMA2D->OMAR = addr;
    DMA2D->OOR  = offline;
    DMA2D->OPFCCR = LTDC_PIXEL_FORMAT_RGB565;
    DMA2D->NLR = (height) | (width << 16);

    DMA2D->IFCR |= DMA2D_IFCR_CTCIF; 
    DMA2D->CR   |= DMA2D_CR_TCIE;
    /*  启动填充 */
    DMA2D->CR |= DMA2D_CR_START;
    /* 阻塞当前调用的任务 */
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever);
    
    //  释放互斥锁
    osMutexRelease(dma2dMutexHandle);
}




/**
 * @brief  使用 DMA2D 将颜色缓冲区数据搬运至显存指定区域
 * @param  sx, sy: 起始坐标
 * @param  ex, ey: 结束坐标
 * @param  color: 指向源颜色缓冲区（如 LVGL 的 color_p）的指针
 */
void ltdc_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color)
{    
    //  抢占互斥锁 (Mutex)
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;
    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint32_t addr   = 0xD0000000 + 2 * (240 * sy + sx); 
    /* 记录当前正在调用的任务 ID */
    drawingTaskHandle = osThreadGetId();
    /*  Cache 管理：确保 DMA2D 读到的是最新的内存数据 */
    SCB_CleanDCache_by_Addr((uint32_t*)color, width * height * 2);
    /*  配置模式与地址 */
    DMA2D->CR      = DMA2D_M2M;                      // 存储器到存储器模式
    DMA2D->FGMAR   = (uint32_t)color;                 // 源：LVGL 缓冲区
    DMA2D->OMAR    = addr;                            // 目：SDRAM 显存
    DMA2D->FGOR    = 0;                               // 源偏移
    DMA2D->OOR     = 240 - width;                     // 目标偏移 (屏幕宽度 - 填充宽度)
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_RGB565;        // 输入格式
    DMA2D->OPFCCR  = LTDC_PIXEL_FORMAT_RGB565;        // 输出格式
    DMA2D->NLR     = (height) | (width << 16);        // 设置宽高    
    /*  开启中断并启动 */
    DMA2D->IFCR |= DMA2D_IFCR_CTCIF;                  // 先清一次标志位
    DMA2D->CR   |= DMA2D_CR_TCIE;                     // 使能传输完成中断
    DMA2D->CR   |= DMA2D_CR_START;                    // 开启搬运
    /* 阻塞当前调用的任务 */
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever);  
    //  释放互斥锁
    osMutexRelease(dma2dMutexHandle);
}
osThreadId_t drawingTaskHandle = NULL; // 记录当前是谁在用 DMA2D

/* 1. 定义互斥量句柄 */
osMutexId_t dma2dMutexHandle;
/* 3. 在初始化函数中创建互斥量  */
void DMA2D_Mutex_Init(void) {
    const osMutexAttr_t Thread_Mutex_attr = {
        "dma2dMutex",                          // 名字
        osMutexRecursive| osMutexPrioInherit, 
        NULL, 0
    };
    dma2dMutexHandle = osMutexNew(&Thread_Mutex_attr);
}

/**
 * @brief  DMA2D 纯色填充函数 (R2M 模式)
 * @param  sx, sy: 起始坐标
 * @param  ex, ey: 结束坐标
 * @param  color:  填充的颜色 (RGB565格式)
 */
void ltdc_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint32_t color)
{
    // 1. 抢占互斥锁 (Mutex)
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;

    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint16_t offline = 240 - width; // 屏幕宽度减去填充宽度
    uint32_t addr = 0xD0000000 + 2 * (240 * sy + sx); // 目标显存地址
    /* 记录当前正在调用的任务 ID */
    drawingTaskHandle = osThreadGetId();    
    
    DMA2D->CR = DMA2D_R2M; 
    DMA2D->OCOLR = color; 
    DMA2D->OMAR = addr;
    DMA2D->OOR  = offline;
    DMA2D->OPFCCR = LTDC_PIXEL_FORMAT_RGB565;
    DMA2D->NLR = (height) | (width << 16);

    DMA2D->IFCR |= DMA2D_IFCR_CTCIF; 
    DMA2D->CR   |= DMA2D_CR_TCIE;
    /*  启动填充 */
    DMA2D->CR |= DMA2D_CR_START;
    /* 阻塞当前调用的任务 */
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever);
    
    //  释放互斥锁
    osMutexRelease(dma2dMutexHandle);
}




/**
 * @brief  使用 DMA2D 将颜色缓冲区数据搬运至显存指定区域
 * @param  sx, sy: 起始坐标
 * @param  ex, ey: 结束坐标
 * @param  color: 指向源颜色缓冲区（如 LVGL 的 color_p）的指针
 */
void ltdc_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color)
{    
    //  抢占互斥锁 (Mutex)
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;
    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint32_t addr   = 0xD0000000 + 2 * (240 * sy + sx); 
    /* 记录当前正在调用的任务 ID */
    drawingTaskHandle = osThreadGetId();
    /*  Cache 管理：确保 DMA2D 读到的是最新的内存数据 */
    SCB_CleanDCache_by_Addr((uint32_t*)color, width * height * 2);
    /*  配置模式与地址 */
    DMA2D->CR      = DMA2D_M2M;                      // 存储器到存储器模式
    DMA2D->FGMAR   = (uint32_t)color;                 // 源：LVGL 缓冲区
    DMA2D->OMAR    = addr;                            // 目：SDRAM 显存
    DMA2D->FGOR    = 0;                               // 源偏移
    DMA2D->OOR     = 240 - width;                     // 目标偏移 (屏幕宽度 - 填充宽度)
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_RGB565;        // 输入格式
    DMA2D->OPFCCR  = LTDC_PIXEL_FORMAT_RGB565;        // 输出格式
    DMA2D->NLR     = (height) | (width << 16);        // 设置宽高    
    /*  开启中断并启动 */
    DMA2D->IFCR |= DMA2D_IFCR_CTCIF;                  // 先清一次标志位
    DMA2D->CR   |= DMA2D_CR_TCIE;                     // 使能传输完成中断
    DMA2D->CR   |= DMA2D_CR_START;                    // 开启搬运
    /* 阻塞当前调用的任务 */
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever);  
    //  释放互斥锁
    osMutexRelease(dma2dMutexHandle);
}

完成之后，即可完成翻转了。
然后发现 字体模糊 且颜色对应不上，我们这边找到原因是LTDC的极性出现了问题
虽然手册写着上升沿采样，但由于 STM32 内部输出逻辑和你的硬件电路配合后，可能导致 Inverted（反相）模式下的采样点反而更接近数据的中心点。

所以将极性设置为 hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IIPC;就立刻清晰多了。
还有一个点是  本来我这边设置的  是RGB565格式
    SPI_WriteComm (0x3A);
    SPI_WriteData (0x55);//565
    但发现效果不好，看了一下原理图是因为 我的R2和R3 连在一起了，而不是R2进行一个浮空。所以还是设置回了
        SPI_WriteComm (0x3A);
    SPI_WriteData (0x66);//565.
    设置完之后 写了一个满屏错位移动的小方块，进行一个性能测试
