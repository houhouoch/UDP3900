#include "power_interface.h"
#include "can_protocol.h"
#include "can_manager.h"
PowerInfo_t PowerInfo = {0};


/**
 * @brief 系统参数出厂默认值初始化
 * @note 当 Flash 读取失败或用户手动恢复出厂设置时调用
 */
void Power_Param_Default_Init(void) {
    // 获取全局结构体指针 (假设你的全局变量名为 PowerInfo)
    OutSet_Def *p = &PowerInfo.outSet;

    // --- 输出基本设置 ---
    p->volt_set = 12.000;         // 初始电压 0V
    p->curr_set = 10.000;         // 初始正向电流 1A
    p->curr_set_neg = -10.000;     // 初始负向电流 -1A
    p->ResIn_set = 0.000;        // 内阻 0Ω
    p->onoff = 0;                // 默认输出关闭

    // --- 1. OVP (过压保护) ---
    p->ovp_set = 61.200;         // 默认设为最大量程略高
    p->ovp_onoff = 0;            // 默认关闭，由用户按需开启
    p->ovp_delayTime = 2000;       // 2000ms 触发延迟

    // --- 2. OCP (过流保护) ---
    p->ocp_set = 21.000;         // 正向 10.5A
    p->ocp_set_neg = -21.000;    // 负向 -10.5A
    p->ocp_onoff = 0;
    p->ocp_delayTime = 2000;

    // --- 3. OPP (过功率保护) ---
    p->opp_set = 525.00;         // 正向 410W
    p->opp_set_neg = -525.00;    // 负向 -410W
    p->opp_onoff = 0;
    p->opp_delayTime = 2000;

    // --- 4. UVP (欠压保护) ---
    p->uvp_set = 61.200;          // 欠压通常设为 0，防止误触发
    p->uvp_onoff = 0;
    p->uvp_warmTime = 2000;      // 启动屏蔽时间 1000ms (1秒)
    p->uvp_delayTime = 2000;

    // --- 5. UCP (欠流保护) ---
    p->ucp_set = 21.000;
    p->ucp_set_neg = -21.000;
    p->ucp_onoff = 0;
    p->ucp_warmTime = 2000;      // 启动屏蔽时间 1000ms
    p->ucp_delayTime = 2000;

    // --- 6. Foldback (折返保护) ---
    p->fold_onoff = 0;
    p->fold_mode = 0;            // 默认 Cv-cccp
    p->fold_delayTime = 2000;
}

/**
 * @brief 更新回读电压
 */
void IF_Power_Set_Readback_Volt(double v) {
    PowerInfo.Read.volt_read = v;
    // 自动计算实时功率 (P = U * I)
    PowerInfo.Read.power_read = PowerInfo.Read.volt_read * PowerInfo.Read.curr_read;
}

/**
 * @brief 更新回读电流
 */
void IF_Power_Set_Readback_Curr(double i) {
    PowerInfo.Read.curr_read = i;
    // 自动计算实时功率
    PowerInfo.Read.power_read = PowerInfo.Read.volt_read * PowerInfo.Read.curr_read;
}



/**
 * @brief  设置总输出开关状态
 * @param  state: 0-OFF, 1-ON
 */
void IF_Power_Set_OutOnOff(uint8_t state) {
    // 1. 更新结构体真值
    PowerInfo.outSet.onoff = state;

    // 2. 同步物理 LED 灯
    Panel_LED_Set(LED_ON_OFF, state);

    // 3. 同步 UI 显示
    if(ui.HOME_PAGE_label_2 != NULL) {
        if(state) {
            // --- 输出开启 (ON) ---
            lv_label_set_text(ui.HOME_PAGE_label_2, "ON");
            lv_obj_set_style_text_color(ui.HOME_PAGE_label_2, lv_palette_main(LV_PALETTE_RED), 0);
            
            // 设置 Vout 标签不透明 (100% 亮度)
            lv_obj_set_style_text_opa(ui.HOME_PAGE_label_Vout, LV_OPA_COVER, 0); 
            lv_obj_set_style_text_opa(ui.HOME_PAGE_label_Iout, LV_OPA_COVER, 0);
            lv_obj_set_style_text_opa(ui.HOME_PAGE_label_VoUnit, LV_OPA_COVER, 0); 
            lv_obj_set_style_text_opa(ui.HOME_PAGE_label_IoUnit, LV_OPA_COVER, 0);      
        } else {
            // --- 输出关闭 (OFF) ---
            lv_label_set_text(ui.HOME_PAGE_label_2, "OFF");
            lv_obj_set_style_text_color(ui.HOME_PAGE_label_2, lv_palette_main(LV_PALETTE_GREY), 0);
            
            // 设置 Vout 标签半透明 (50% 亮度)
            lv_obj_set_style_text_opa(ui.HOME_PAGE_label_Vout, LV_OPA_50, 0); 
            lv_obj_set_style_text_opa(ui.HOME_PAGE_label_Iout, LV_OPA_50, 0);
            lv_obj_set_style_text_opa(ui.HOME_PAGE_label_VoUnit, LV_OPA_50, 0); 
            lv_obj_set_style_text_opa(ui.HOME_PAGE_label_IoUnit, LV_OPA_50, 0);             
        }
    }

    // 2. 发送物理 CAN 指令
    // --- 2. CAN 指令序列分发 ---
    if (state == 1) {
        // 执行开机动作：DC EN -> BUCK EN
        Power_System_Start_Sequence();
        printf(">>> [System] Starting: DCDC then BUCK...\r\n");
    } 
    else {
        // 执行关机动作：DC STOP -> BUCK STOP
        Power_System_Stop_Sequence();
        printf(">>> [System] Stopping: DCDC then BUCK...\r\n");
    }
}


uint8_t IF_Power_Get_OutOnOff(void) {
    return PowerInfo.outSet.onoff;
}



/**
 * @brief 系统锁定/解锁控制接口
 * @param state: 1-锁定, 0-解锁
 */
void UI_IF_Power_Set_Lock(uint8_t state) {
    // 1. 更新结构体真值
    PowerInfo.outSet.lock = state;
    // 3. UI 视觉反馈 (建议在顶部状态栏放一个锁图标)
    if(ui.HOME_PAGE_img_3 != NULL) {
        if(state) {
            // 显示锁图标 (使用 LVGL 自带符号)
            lv_obj_clear_flag(ui.HOME_PAGE_img_3, LV_OBJ_FLAG_HIDDEN);
        } else {
            // 隐藏锁图标
            lv_obj_add_flag(ui.HOME_PAGE_img_3, LV_OBJ_FLAG_HIDDEN);
        }
    }

   // printf("[System] Keypad %s\n", state ? "LOCKED" : "UNLOCKED");
}


/*
 * @brief
 * @details     输出电压设置
 */
float IF_Power_Get_OutVolt(void)
{
    return PowerInfo.outSet.volt_set;
}
void IF_Power_Set_OutVolt(float value)
{
    
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
        float setVol = value;
        PowerInfo.outSet.volt_set = setVol;    
        CAN_Protocol_Send_Control_Float(CONTROL_SET_OUTV, setVol);
        // 5. 释放锁
    osMutexRelease(can_tx_mutex_handle);
}


/*
 * @brief
 * @details     输出电流设置
 */
float IF_Power_Get_OutCurr(void)
{
    return PowerInfo.outSet.curr_set;
}
void IF_Power_Set_OutCurr(float value)
{
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
        float setCurr = value;
    PowerInfo.outSet.curr_set = setCurr;
    CAN_Protocol_Send_Control_Float(CONTROL_SET_OUTSI, setCurr);
    osMutexRelease(can_tx_mutex_handle);
}

/*
 * @brief
 * @details     输出负相电流设置
 */
float IF_Power_Get_OutCurr_Neg(void)
{
    return PowerInfo.outSet.curr_set_neg;
}
void IF_Power_Set_OutCurr_Neg(float value)
{
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
        float setCurr_neg = value;
        PowerInfo.outSet.curr_set_neg = setCurr_neg;
    osMutexRelease(can_tx_mutex_handle);
}

//
/* ----------------------------------------------------------------
    1. OVP (Over Voltage Protection) - 过压保护
   ---------------------------------------------------------------- */

float IF_Power_Get_OVP_Volt(void) {
    return (float)PowerInfo.outSet.ovp_set;
}
void IF_Power_Set_OVP_Volt(float value) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ovp_set = value;
    osMutexRelease(can_tx_mutex_handle);
}

uint8_t IF_Power_Get_OVP_State(void) {
    return PowerInfo.outSet.ovp_onoff;
}
void IF_Power_Set_OVP_State(uint8_t state) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ovp_onoff = state;
    osMutexRelease(can_tx_mutex_handle);
}

int16_t IF_Power_Get_OVP_Delay(void) {
    return PowerInfo.outSet.ovp_delayTime;
}
void IF_Power_Set_OVP_Delay(int16_t value_ms) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ovp_delayTime = value_ms;
    osMutexRelease(can_tx_mutex_handle);
}
/* ----------------------------------------------------------------
    2. OCP (Over Current Protection) - 访问接口
   ---------------------------------------------------------------- */

// --- 正向电流阈值 ---
float IF_Power_Get_OCP_Pos_Curr(void) {
    return (float)PowerInfo.outSet.ocp_set;
}
void IF_Power_Set_OCP_Pos_Curr(float value) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ocp_set = (double)value;
    osMutexRelease(can_tx_mutex_handle);
}

// --- 负向电流阈值 ---
float IF_Power_Get_OCP_Neg_Curr(void) {
    return (float)PowerInfo.outSet.ocp_set_neg;
}
void IF_Power_Set_OCP_Neg_Curr(float value) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ocp_set_neg = (double)value;
    osMutexRelease(can_tx_mutex_handle);
}

// --- OCP 延迟时间 ---
int16_t IF_Power_Get_OCP_Delay(void) {
    return PowerInfo.outSet.ocp_delayTime;
}
void IF_Power_Set_OCP_Delay(int16_t value_ms) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ocp_delayTime = value_ms;
    osMutexRelease(can_tx_mutex_handle);
}

// --- OCP 开关状态 ---
uint8_t IF_Power_Get_OCP_State(void) {
    return PowerInfo.outSet.ocp_onoff;
}
void IF_Power_Set_OCP_State(uint8_t state) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ocp_onoff = state;
    osMutexRelease(can_tx_mutex_handle);
}

/* ----------------------------------------------------------------
    3. OPP (Over Power Protection) - 过功率保护
   ---------------------------------------------------------------- */
// --- 正向功率阈值 ---
float IF_Power_Get_OPP_Pos_Power(void) {
    return (float)PowerInfo.outSet.opp_set;
}
void IF_Power_Set_OPP_Pos_Power(float value) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.opp_set = (double)value;
    osMutexRelease(can_tx_mutex_handle);
}

// --- 负向功率阈值 ---
float IF_Power_Get_OPP_Neg_Power(void) {
    return (float)PowerInfo.outSet.opp_set_neg; // 需确保 OutSet_Def 结构体中有此字段
}
void IF_Power_Set_OPP_Neg_Power(float value) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.opp_set_neg = (double)value;
    osMutexRelease(can_tx_mutex_handle);
}

// --- OPP 状态开关 ---
uint8_t IF_Power_Get_OPP_State(void) {
    return PowerInfo.outSet.opp_onoff;
}
void IF_Power_Set_OPP_State(uint8_t state) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.opp_onoff = state;
    osMutexRelease(can_tx_mutex_handle);
}

// --- OPP 延迟时间 ---
int16_t IF_Power_Get_OPP_Delay(void) {
    return PowerInfo.outSet.opp_delayTime;
}
void IF_Power_Set_OPP_Delay(int16_t value_ms) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.opp_delayTime = value_ms;
    osMutexRelease(can_tx_mutex_handle);
}
/* ----------------------------------------------------------------
    4. UVP (Under Voltage Protection) - 欠压保护接口
   ---------------------------------------------------------------- */

float IF_Power_Get_UVP_Volt(void) {
    return (float)PowerInfo.outSet.uvp_set;
}
void IF_Power_Set_UVP_Volt(float value) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.uvp_set = (double)value;
    osMutexRelease(can_tx_mutex_handle);
}

/** @brief 获取 UVP 屏蔽时间 (ms) */
int16_t IF_Power_Get_UVP_WarmTime(void) {
    return PowerInfo.outSet.uvp_warmTime;
}

/** @brief 设置 UVP 屏蔽时间 (ms) */
void IF_Power_Set_UVP_WarmTime(int16_t value_ms) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.uvp_warmTime = value_ms;
    osMutexRelease(can_tx_mutex_handle);
}

int16_t IF_Power_Get_UVP_Delay(void) {
    return PowerInfo.outSet.uvp_delayTime;
}
void IF_Power_Set_UVP_Delay(int16_t value_ms) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.uvp_delayTime = value_ms;
    osMutexRelease(can_tx_mutex_handle);
}

/* ----------------------------------------------------------------
    5. UCP (Under Current Protection) - 欠流保护接口 (支持正负向)
   ---------------------------------------------------------------- */

// --- 正向欠流阈值 ---
float IF_Power_Get_UCP_Pos_Curr(void) {
    return (float)PowerInfo.outSet.ucp_set;
}
void IF_Power_Set_UCP_Pos_Curr(float value) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ucp_set = (double)value;
    osMutexRelease(can_tx_mutex_handle);
}

// --- 负向欠流阈值 ---
float IF_Power_Get_UCP_Neg_Curr(void) {
    return (float)PowerInfo.outSet.ucp_set_neg; // 需确保结构体 OutSet_Def 已添加此字段
}
void IF_Power_Set_UCP_Neg_Curr(float value) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ucp_set_neg = (double)value;
    osMutexRelease(can_tx_mutex_handle);
}

/** @brief 获取 UCP 屏蔽时间 (ms) */
int16_t IF_Power_Get_UCP_WarmTime(void) {
    return PowerInfo.outSet.ucp_warmTime;
}

/** @brief 设置 UCP 屏蔽时间 (ms) */
void IF_Power_Set_UCP_WarmTime(int16_t value_ms) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ucp_warmTime = value_ms;
    osMutexRelease(can_tx_mutex_handle);
}
// --- UCP 延迟时间 ---
int16_t IF_Power_Get_UCP_Delay(void) {
    return PowerInfo.outSet.ucp_delayTime;
}
void IF_Power_Set_UCP_Delay(int16_t value_ms) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.ucp_delayTime = value_ms;
    osMutexRelease(can_tx_mutex_handle);
}
/* ----------------------------------------------------------------
    6. Foldback (折返保护)
   ---------------------------------------------------------------- */

uint8_t IF_Power_Get_Foldback_State(void) {
    return PowerInfo.outSet.fold_onoff;
}
void IF_Power_Set_Foldback_State(uint8_t state) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.fold_onoff = state;
    osMutexRelease(can_tx_mutex_handle);
}

uint8_t IF_Power_Get_Foldback_Mode(void) {
    return PowerInfo.outSet.fold_mode;
}
void IF_Power_Set_Foldback_Mode(uint8_t mode) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.fold_mode = mode;
    osMutexRelease(can_tx_mutex_handle);
}

int16_t IF_Power_Get_Foldback_Delay(void) {
    return PowerInfo.outSet.fold_delayTime;
}
void IF_Power_Set_Foldback_Delay(int16_t value_ms) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.fold_delayTime = value_ms;
    osMutexRelease(can_tx_mutex_handle);
}

// 获取模式
uint8_t IF_Power_Get_Fold_Mode(void) {
    return PowerInfo.outSet.fold_mode;
}
// 设置模式 (带互斥锁)
void IF_Power_Set_Fold_Mode(uint8_t mode) {
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
    PowerInfo.outSet.fold_mode = mode;
    osMutexRelease(can_tx_mutex_handle);
}
