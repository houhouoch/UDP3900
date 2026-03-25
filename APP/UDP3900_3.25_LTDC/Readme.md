这里实现了显示屏的点亮，
下面为注意事项：
1、DOTCLK 周期时间 ($T_{CYCD}$)：最小为 33 ns --》
在实际配置 STM32 的 LTDC 时，将频率设定在 20 MHz 至 25 MHz 之间。这既能满足 33 ns 最小周期的限制，也能保证在 240x960 分辨率下达到流畅的刷新率（通常为 60Hz）
2、此屏幕为切割屏，原是360*960大小  像素切割成240*960
所以我们要确认 他是切割哪一边，经过设置
  pLayerCfg.WindowX0 = 150;
  pLayerCfg.WindowX1 = 360;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 960;
  pLayerCfg.Backcolor.Blue = 255;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
   //填充屏幕为红色
  uint16_t *fb = (uint16_t *)0xD0000000;
  for(uint32_t i = 0; i < 240 * 960; i++) fb[i] = 0xF800; // 纯红
    
  可知道 这个红色在右边显示，左边那一条为蓝色底色。得出 这个屏幕是 切割左边。
3、关于格式设置
      SPI_WriteComm (0x3A);
    SPI_WriteData (0x55);//0x66
    SPI_WriteComm (0x29);
    填入0x55 为RGB565格式
    0x55：代表 RGB565 (16-bit)
    0x66：代表 RGB666 (18-bit)
