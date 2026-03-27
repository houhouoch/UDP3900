# 📁 LVGL 模块化移植与目录重构说明

针对 **LVGL v8.3** 移植过程繁琐、配置文件众多的特点，本项目采取了**“独立文件夹、模块化管理”**的策略，将 GUI 框架相关的底层驱动与应用层代码进行深度隔离。

---

## 🛠️ 1. 为什么要进行目录分离？

*   **逻辑解耦**：LVGL 涉及源码、配置文件（`lv_conf.h`）以及显示/输入设备接口（`porting`），将其独立存放可避免与 MCU 的基础外设驱动（HAL/BSP）混淆。
*   **工程洁癖**：由于 LVGL 源码体量巨大，通过独立文件夹管理，可以使主工程目录保持清爽，降低开发者的认知负担。
*   **实验迭代**：方便后续针对不同的显示架构（如：DMA2D 搬运模式 vs 零拷贝模式）进行快速的代码更迭与版本切换，而无需改动底层 BSP 逻辑。

---
## 🧪 3. 移植验证实验：Hello World

为了验证 LVGL 内核、显示驱动以及坐标映射是否正确工作，我们设计了一个简单的**“左上角定点验证”**实验。

### 🚩 验证目标
在屏幕的逻辑原点 **(0, 0)** 位置显示一个交互按钮，确保渲染方向与物理坐标系完全匹配。

### 🛠️ 实验代码 (C 语言)
```c
/**
 * @brief LVGL 移植成功验证函数
 */
void lv_port_verify_test(void)
{
    lv_init();
    lv_port_disp_init();
    
    lv_obj_t * btn = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn, 100, 50);
    
    // 2. 将按钮对齐到左上角 (逻辑坐标 0,0)
    lv_obj_align(btn, LV_ALIGN_TOP_LEFT, 0, 0); 
    
    // 3. 给按钮上色以便观察
    lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_GREEN), 0);

    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, "TOP LEFT");
    lv_obj_center(label);
}
```

### ✅ 现象判定
*   **渲染成功**：屏幕左上角准确出现蓝色按钮。
*   **文本正常**：按钮中心清晰可见 "TOP LEFT" 字样。
*   **坐标确认**：若按钮出现在其他角落，说明 `lv_port_disp.c` 中的坐标映射或屏幕旋转参数（Rotation）配置有误。

---
