# 🚀 ST7701S + STM32H750 LVGL 移植与 90° 旋转优化手册

本项目基于 **STM32H750** 驱动 **ST7701S** 控制器的长条切割屏（物理分辨率 240x960），重点解决了特殊比例屏幕的软件旋转性能瓶颈与硬件采样兼容性问题。

---

## 1. 项目背景与难点

*   **硬件限制**：ST7701S 寄存器 `0x36` 仅支持水平/垂直镜像，不支持物理 90° 旋转。
*   **软件挑战**：底层 `ltdc_color_fill` 直接操作线性显存，无法通过简单坐标映射实现旋转。
*   **解决方案**：启用 **LVGL 软件旋转 (Software Rotation)** 配合 **DMA2D (Chrom-ART)** 硬件加速。

---

## 2. LVGL 核心配置 (lv_port_disp.c)

为了开启软件层面的坐标转换，需在显示驱动初始化中进行如下设置：

```c
/* 1. 开启软件旋转 */
disp_drv.sw_rotate = 1;
disp_drv.rotated = LV_DISP_ROT_90;

/* 2. 开启时钟自定义 */
// 必须在 lv_conf.h 中设置 LV_TICK_CUSTOM 1
// 否则 LVGL 定时器不运行，界面将无法响应动画。
```

> **⚠️ 避坑点**：软件旋转会消耗额外的 CPU 计算。LVGL 会在中间缓冲区完成旋转运算后再调用 `flush_cb`。因此，必须确保分配给 LVGL 的绘图缓冲区足够大以容纳旋转后的数据。

---

## 3. DMA2D 性能优化与 RTOS 互斥锁

利用 **DMA2D** 接管显存填充与搬运，释放 CPU 算力。通过 **Recursive Mutex (递归互斥锁)** 与 **Thread Flags** 解决多任务环境下的总线竞争。



### 3.1 互斥锁与任务记录初始化
```c
osThreadId_t drawingTaskHandle = NULL; // 记录当前占用 DMA2D 的任务
osMutexId_t dma2dMutexHandle;          // 互斥量句柄

void DMA2D_Mutex_Init(void) {
    const osMutexAttr_t Thread_Mutex_attr = {
        "dma2dMutex",
        osMutexRecursive | osMutexPrioInherit, // 递归模式 + 优先级继承
        NULL, 0
    };
    dma2dMutexHandle = osMutexNew(&Thread_Mutex_attr);
}
```

### 3.2 DMA2D 纯色填充 (R2M 模式)
用于清屏或大面积背景填充。地址计算公式：
$$Addr = 0xD0000000 + 2 \times (240 \times sy + sx)$$

```c
void ltdc_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint32_t color){
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;

    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint16_t offline = 240 - width; // 逻辑宽度偏移
    uint32_t addr = 0xD0000000 + 2 * (240 * sy + sx); 
    
    drawingTaskHandle = osThreadGetId();    
    
    DMA2D->CR = DMA2D_R2M; 
    DMA2D->OCOLR = color; 
    DMA2D->OMAR = addr;
    DMA2D->OOR  = offline;
    DMA2D->OPFCCR = LTDC_PIXEL_FORMAT_RGB565;
    DMA2D->NLR = (height) | (width << 16);

    DMA2D->IFCR |= DMA2D_IFCR_CTCIF; 
    DMA2D->CR   |= DMA2D_CR_TCIE;
    DMA2D->CR   |= DMA2D_CR_START;
    
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever);
    osMutexRelease(dma2dMutexHandle);
}
```

### 3.3 DMA2D 颜色搬运 (M2M 模式)
将渲染缓冲区数据搬运至 SDRAM 显存。

```c
void ltdc_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color){   
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;

    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint32_t addr   = 0xD0000000 + 2 * (240 * sy + sx); 

    drawingTaskHandle = osThreadGetId();

    /* 核心补丁：清理 D-Cache 确保 DMA2D 读到的是 CPU 写入的最新像素 */
    SCB_CleanDCache_by_Addr((uint32_t*)color, width * height * 2);

    DMA2D->CR      = DMA2D_M2M;
    DMA2D->FGMAR   = (uint32_t)color;                 // 源：LVGL 缓冲区
    DMA2D->OMAR    = addr;                           // 目：SDRAM 显存
    DMA2D->FGOR    = 0;                              
    DMA2D->OOR     = 240 - width;                    
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_RGB565;        
    DMA2D->OPFCCR  = LTDC_PIXEL_FORMAT_RGB565;        
    DMA2D->NLR     = (height) | (width << 16);       

    DMA2D->IFCR |= DMA2D_IFCR_CTCIF;                  
    DMA2D->CR   |= DMA2D_CR_TCIE | DMA2D_CR_START;                    
    
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever);  
    osMutexRelease(dma2dMutexHandle);
}
```

---

## 4. 图像质量调优（核心避坑）

### 4.1 LTDC 采样极性修复模糊
**问题**：字体模糊、颜色淡，边缘有重影。
**原因**：LTDC 时钟采样极性与物理硬件不匹配。
**解决**：将时钟极性设置为反相（Inverted），确保在数据稳定期进行采样。



```c
hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IIPC; // 使用反相采样模式
```

### 4.2 硬件引脚冲突导致色彩异常 (0x3A 模式)
**问题**：初始化 RGB565（0x55）效果极差，画面有锯齿。
**原因**：硬件原理图中 `R2` 与 `R3` 被强行连通，导致 16-bit 模式下数据位对齐错误。
**对策**：将屏幕初始化为 18-bit 逻辑（0x66），但软件底层依然传输 16-bit 数据。利用硬件物理连线自动完成高位对齐。

```c
SPI_WriteComm (0x3A);
SPI_WriteData (0x66); // 使用 18-bit 模式适配特定的硬件连线
```

---

## 5. 性能测试报告

*   **测试程序**：满屏错位移动方块（Staggered Boxes）。
*   **硬件频率**：CPU @ 480MHz, LTDC Clock @ 25MHz。
*   **结论**：
    1.  开启软件旋转 90° 后，系统仍能维持 50FPS 以上的重绘速度。
    2.  递归互斥锁成功防止了 UI 任务与高优先级中断任务抢夺 DMA2D 导致的死锁。
    3.  反相采样解决了长条屏由于布线延迟引起的信号完整性问题。

---
**开发者备注**：在 H7 系列上使用 DMA 必须关注 **D-Cache 一致性**，否则会出现由于 CPU 缓存未刷回内存导致的“花屏”或“旧帧残留”。
