#include "Menu_Protect_Editor.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
/* --- 步进数组定义 (内部静态) --- */
static const double Prot_V_step[] = {0.001, 0.01, 0.1, 1.0, 10.0}; 
static const double Prot_A_step[] = {0.001, 0.01, 0.1, 1.0, 10.0};
static const double Prot_P_step[] = {0.01, 0.1, 1.0, 10.0, 100.0}; // 功率步进
static const double Prot_D_step[] = {0.001, 0.01, 0.1, 1.0,10.0};      // 延迟步进 (s)
#define FMT_VOLT            "%0.3fV"
#define FMT_CURR            "%0.3fA"
#define FMT_CURR_neg        "%0.3fA"
#define FMT_DELAY           "%0.3fS"
#define FMT_POWER           "%0.2fW"
#define FMT_POWER_neg       "%0.2fW"
/* --- 内部私有辅助函数 --- */
/**
 * @brief 选位高亮核心逻辑 (同步自 HomePage)
 */
void label_setSelNum(lv_obj_t *label, uint16_t numpos, const char *text)
{
    if(label == NULL) return;
    uint16_t strLen = strlen(text);
    uint16_t bitindex = 0;
    for(int16_t i = strLen - 1; i >= 0; --i) {
        if((('0' <= text[i]) && (text[i] <= '9')) || (text[i] == ' ')) {
            if(bitindex == numpos) {
                lv_label_set_text_sel_start(label, i);
                lv_label_set_text_sel_end(label, i + 1);
                return;
            }
            bitindex++;
        }
    }
}
static void Set_RefreshUI_Protect(lv_obj_t *obj, uint8_t *editIndex, const char *dispfmt, double value)
{
    if(obj == NULL) return;
    char buf[32];
    sprintf(buf, dispfmt, value);
    lv_label_set_text(obj, buf);

    if(editIndex != NULL) {
        label_setSelNum(obj, *editIndex, buf);
    } else {
        // 必须显式关闭选择，否则方块会残留在原来的数字上
        lv_label_set_text_sel_start(obj, LV_LABEL_TEXT_SELECTION_OFF);
        lv_label_set_text_sel_end(obj, LV_LABEL_TEXT_SELECTION_OFF);
    }
}

/* ----------------------------------------------------------------
    2. 核心逻辑处理 (全通用，以后基本不用改这里)
   ---------------------------------------------------------------- */
/**
 * @brief 保护项逻辑处理器 (完全对齐主页逻辑)
 * @param index_ptr 指向该 Handler 独有的静态位选索引
 * @param cfg 该项的配置信息
 * @param is_neg 是否为负值调节
 */
static void protect_item_logic_core(lv_event_t * e, uint8_t * index_ptr, const Protect_Item_Cfg_t * cfg, bool is_neg)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);
    
    // 1. 获取物理值并进行缩放处理 (例如 ms -> S)
    double current_val = cfg->get_val() / cfg->scale;

    switch(code)
    {
        case LV_EVENT_FOCUSED: {
            double disp_val = is_neg ? fabs(current_val) : current_val;
            Set_RefreshUI_Protect(obj, NULL, cfg->fmt, disp_val); 
            break;
        }
        
        case LV_EVENT_CLICKED: {
            // 只有点击了以后，才真正开始“编辑模式”，显示位选光标
            *index_ptr = cfg->init_index; 
            double disp_val = is_neg ? fabs(current_val) : current_val;
            Set_RefreshUI_Protect(obj, index_ptr, cfg->fmt, disp_val);
            break;
        }
        
        case LV_EVENT_KEY: {
            // --- [关键] 在这里保留数字键盘拦截 (如果需要) ---
            // NumberInput_Process(7, cfg->set_val, cfg, is_neg); 

            lv_key_t key = lv_event_get_key(e);                        
            switch(key) {
                case LV_KEY_UP:
                    if(is_neg) 
                        current_val -= cfg->steps[*index_ptr]; // 负向通道：UP 让数值更负（绝对值变大）
                    else 
                        current_val += cfg->steps[*index_ptr]; // 正向通道：UP 让数值更正
                    break;
                    
                case LV_KEY_DOWN:
                    if(is_neg) 
                        current_val += cfg->steps[*index_ptr]; // 负向通道：DOWN 向 0 靠近
                    else 
                        current_val -= cfg->steps[*index_ptr]; // 正向通道：DOWN 减小
                    break;

                case LV_KEY_LEFT:
                    if(*index_ptr < cfg->max_index) (*index_ptr)++;
                    break;
                case LV_KEY_RIGHT:
                    if(*index_ptr > 0) (*index_ptr)--;
                    break;
                    
                case LV_KEY_ENTER:
                case LV_KEY_ESC:
                    Tree_UI_Sel_Exit();
                    return;
            }
            
            // --- 边界限制 (完全对齐 Home) ---
            if(is_neg && current_val > 0.0) current_val = 0.0; // 负向通道不能跨越到正数
            if(!is_neg && current_val < 0.0) current_val = 0.0; // 正向通道不能低于 0
            
            // 值域限幅
            if(current_val < cfg->min_val) current_val = cfg->min_val;
            if(current_val > cfg->max_val) current_val = cfg->max_val;

            
            // 写入底层 (还原缩放，例如 S -> ms)
            if (cfg->scale > 1.1) {
                // 针对时间类（Scale = 1000），强制四舍五入到最近的毫秒整数
                cfg->set_val(round(current_val * cfg->scale));
            } else {
                // 针对电压电流类（Scale = 1.0），直接写入，保持浮点精度
                cfg->set_val(current_val * cfg->scale);
            }

            // 3. 为了防止 current_val 本身在多次加法后产生漂移
            // 每次设置完后，重新从底层同步一次精准的值
            current_val = cfg->get_val() / cfg->scale;
            
            // 刷新显示：直接传真实值，让系统根据数值正负自动打印负号 (对齐 Home)
            Set_RefreshUI_Protect(obj, index_ptr, cfg->fmt, current_val);
            break;
        }

        case LV_EVENT_DEFOCUSED: {
            // 失去焦点，隐藏光标刷新
            double disp_val = is_neg ? fabs(current_val) : current_val;
            Set_RefreshUI_Protect(obj, NULL, cfg->fmt, disp_val);
            break;
        }
        default: break;
    }
}

/* ----------------------------------------------------------------
    3. 适配器与配置表 (如果要加 OCP/OPP，只需在这里加几行)
   ---------------------------------------------------------------- */
// --- OVP Voltage ---
// 定义适配器函数（如果底层接口参数类型不匹配，在这里强转）
static double _get_ovp_v(void) { return (double)IF_Power_Get_OVP_Volt(); }
static void _set_ovp_v(double v) { IF_Power_Set_OVP_Volt((float)v); }
// --- OVP Delay ---
static double _get_ovp_d(void) { return (double)IF_Power_Get_OVP_Delay(); }
static void _set_ovp_d(double ms) { IF_Power_Set_OVP_Delay((int16_t)ms); }
// --- OCP (Over Current) ---
static double _get_ocp_pos_i(void) { return (double)IF_Power_Get_OCP_Pos_Curr(); }
static void   _set_ocp_pos_i(double i) { IF_Power_Set_OCP_Pos_Curr((float)i); }

// --- OCP Negative Current ---
static double _get_ocp_neg_i(void) { return (double)IF_Power_Get_OCP_Neg_Curr(); }
static void   _set_ocp_neg_i(double i) { IF_Power_Set_OCP_Neg_Curr((float)i); }

// --- OCP Delay ---
static double _get_ocp_d(void) { return (double)IF_Power_Get_OCP_Delay(); }
static void   _set_ocp_d(double ms) { IF_Power_Set_OCP_Delay((int16_t)ms); }

// --- OPP (Over Power) ---
/* --- OPP 访问接口实现 --- */
static double _get_opp_pos_p(void) { return (double)IF_Power_Get_OPP_Pos_Power(); }
static void   _set_opp_pos_p(double p) { IF_Power_Set_OPP_Pos_Power((float)p); }

static double _get_opp_neg_p(void) { return (double)IF_Power_Get_OPP_Neg_Power(); }
static void   _set_opp_neg_p(double p) { IF_Power_Set_OPP_Neg_Power((float)p); }

static double _get_opp_d(void) { return (double)IF_Power_Get_OPP_Delay(); }
static void   _set_opp_d(double ms) { IF_Power_Set_OPP_Delay((int16_t)ms); }

// --- UVP (Under Voltage) ---
// --- UVP 电压 ---
static double _get_uvp_v(void) { return (double)IF_Power_Get_UVP_Volt(); }
static void   _set_uvp_v(double v) { IF_Power_Set_UVP_Volt((float)v); }

// --- UVP 屏蔽时间 (Warm-up) ---
static double _get_uvp_warm(void) { return (double)IF_Power_Get_UVP_WarmTime(); }
static void   _set_uvp_warm(double ms) { IF_Power_Set_UVP_WarmTime((int16_t)ms); }

// --- UVP 延迟时间 (Delay) ---
static double _get_uvp_d(void) { return (double)IF_Power_Get_UVP_Delay(); }
static void   _set_uvp_d(double ms) { IF_Power_Set_UVP_Delay((int16_t)ms); }

// --- UCP (Under Current) ---
// --- UCP 正向电流 ---
static double _get_ucp_pos_i(void) { return (double)IF_Power_Get_UCP_Pos_Curr(); }
static void   _set_ucp_pos_i(double i) { IF_Power_Set_UCP_Pos_Curr((float)i); }

// --- UCP 负向电流 ---
static double _get_ucp_neg_i(void) { return (double)IF_Power_Get_UCP_Neg_Curr(); }
static void   _set_ucp_neg_i(double i) { IF_Power_Set_UCP_Neg_Curr((float)i); }

// --- UCP 屏蔽时间 (Warm-up) ---
static double _get_ucp_warm(void) { return (double)IF_Power_Get_UCP_WarmTime(); }
static void   _set_ucp_warm(double ms) { IF_Power_Set_UCP_WarmTime((int16_t)ms); }

// --- UCP 延迟时间 (Delay) ---
static double _get_ucp_d(void) { return (double)IF_Power_Get_UCP_Delay(); }
static void   _set_ucp_d(double ms) { IF_Power_Set_UCP_Delay((int16_t)ms); }

// --- Foldback ---
static double _get_fold_d(void) { return (double)IF_Power_Get_Foldback_Delay(); }
static void   _set_fold_d(double ms) { IF_Power_Set_Foldback_Delay((int16_t)ms); }


const Protect_Item_Cfg_t CFG_OVP_VOLT = {
    .fmt        = FMT_VOLT,
    .steps      = Prot_V_step,
    .max_index  = 4,            // 对应步进数组下标 (0~4)
    .init_index = 3,            // 初始位选位置
    .scale      = 1.0,          // 缩放比例
    .min_val    = 0.000,        // 保护下限 (V)
    .max_val    = 61.200,       // 【修正】保护上限 (V)
    .get_val    = _get_ovp_v,
    .set_val    = _set_ovp_v,  
};

const Protect_Item_Cfg_t CFG_OVP_DELAY = {
    .fmt = FMT_DELAY,
    .steps = Prot_D_step,
    .max_index = 4,
    .init_index = 3,
    .scale = 1000.0, // 底层是ms，UI是S
    .min_val    = 0.000,        
    .max_val    = 10.000,       
    .get_val = _get_ovp_d,
    .set_val = _set_ovp_d
};

/* --- OCP 正向电流配置 --- */
const Protect_Item_Cfg_t CFG_OCP_POS_I = {
    .fmt = FMT_CURR,        // "%0.3fA"
    .steps = Prot_A_step,
    .max_index = 5,         // 基于 Prot_A_step 数组长度
    .init_index = 3,        // 初始位选位置
    .scale = 1.0,
    .min_val    = 0.000,        
    .max_val    = 21.000, 
    .get_val = _get_ocp_pos_i,
    .set_val = _set_ocp_pos_i
};

/* --- OCP 负向电流配置 --- */
const Protect_Item_Cfg_t CFG_OCP_NEG_I = {
    .fmt = FMT_CURR,        // "%0.3fA"
    .steps = Prot_A_step,
    .max_index = 5,
    .init_index = 3,
    .scale = 1.0,
    .min_val    = -21.000,        
    .max_val    = 0.000,
    .get_val = _get_ocp_neg_i,
    .set_val = _set_ocp_neg_i
};

/* --- OCP 延迟配置 --- */
const Protect_Item_Cfg_t CFG_OCP_DELAY = {
    .fmt = FMT_DELAY,       // "%0.3fS"
    .steps = Prot_D_step,
    .max_index = 4,
    .init_index = 3,
    .scale = 1000.0,        // 底层是 ms，显示是 S
    .min_val    = 0.000,        
    .max_val    = 10.000,
    .get_val = _get_ocp_d,
    .set_val = _set_ocp_d
};

/* --- OPP Configs --- */
/* --- OPP 正向功率配置 (0.00W ~ 410.00W) --- */
const Protect_Item_Cfg_t CFG_OPP_POS_P = {
    .fmt = FMT_POWER,       // "%0.2fW"
    .steps = Prot_P_step,   // {0.01, 0.1, 1.0, 10.0, 100.0}
    .max_index = 4,         // 5个元素，索引 0~4
    .init_index = 2,        // 初始位选在 1.00W 位
    .scale = 1.0,
    .min_val = 0.00,        // 正向最小 0
    .max_val = 525.00,      // 假设硬件上限 400W + 10W 余量
    .get_val = _get_opp_pos_p,
    .set_val = _set_opp_pos_p
};

/* --- OPP 负向功率配置 (-410.00W ~ 0.00W) --- */
const Protect_Item_Cfg_t CFG_OPP_NEG_P = {
    .fmt = FMT_POWER_neg,   // "-%0.2fW"
    .steps = Prot_P_step,
    .max_index = 4,
    .init_index = 2,
    .scale = 1.0,
    .min_val = -525.00,     // 负向底限
    .max_val = 0.00,        // 负向最大不能超过 0
    .get_val = _get_opp_neg_p,
    .set_val = _set_opp_neg_p
};

/* --- OPP 延迟配置 (0.000S ~ 10.000S) --- */
const Protect_Item_Cfg_t CFG_OPP_DELAY = {
    .fmt = FMT_DELAY,       // "%0.3fS"
    .steps = Prot_D_step,
    .max_index = 4,
    .init_index = 3,
    .scale = 1000.0,
    .min_val = 0.000,
    .max_val = 10.000,
    .get_val = _get_opp_d,
    .set_val = _set_opp_d
};


/* --- UVP Configs --- */
const Protect_Item_Cfg_t CFG_UVP_VOLT = {
    .fmt = FMT_VOLT,
    .steps = Prot_V_step,
    .max_index = 4,
    .init_index = 3,
    .scale = 1.0,
    .min_val = 0.000,
    .max_val = 61.200,
    .get_val = _get_uvp_v,
    .set_val = _set_uvp_v
};

/* --- UVP 屏蔽/预热时间配置 (核心新增) --- */
const Protect_Item_Cfg_t CFG_UVP_WARM = {
    .fmt = FMT_DELAY,       // 使用 "%0.3fS" 格式
    .steps = Prot_D_step,   // 使用时间步进数组
    .max_index = 4,
    .init_index = 3,
    .scale = 1000.0,        // 换算：底层 ms -> UI 秒
    .min_val = 0.000,
    .max_val = 30.000,      // 预热时间通常可以设长一点
    .get_val = _get_uvp_warm,
    .set_val = _set_uvp_warm
};


const Protect_Item_Cfg_t CFG_UVP_DELAY = {
    .fmt = FMT_DELAY,
    .steps = Prot_D_step,
    .max_index = 4,
    .init_index = 3,
    .scale = 1000.0,
    .min_val = 0.000,
    .max_val = 10.000,
    .get_val = _get_uvp_d,
    .set_val = _set_uvp_d
};

/* --- UCP Configs --- */
/* --- UCP 正向电流配置  --- */
const Protect_Item_Cfg_t CFG_UCP_POS_I = {
    .fmt = FMT_CURR,        // "%0.3fA"
    .steps = Prot_A_step,
    .max_index = 4,         
    .init_index = 3,
    .scale = 1.0,
    .min_val = 0.000,
    .max_val = 21.000,
    .get_val = _get_ucp_pos_i,
    .set_val = _set_ucp_pos_i
};

/* --- UCP 负向电流配置 --- */
const Protect_Item_Cfg_t CFG_UCP_NEG_I = {
    .fmt = FMT_CURR_neg,    // "-%0.3fA"
    .steps = Prot_A_step,
    .max_index = 4,
    .init_index = 3,
    .scale = 1.0,
    .min_val = -21.000,
    .max_val = 0.000,       // 负向上限为 0
    .get_val = _get_ucp_neg_i,
    .set_val = _set_ucp_neg_i
};

/* --- UCP 屏蔽/预热时间配置 (核心新增) --- */
const Protect_Item_Cfg_t CFG_UCP_WARM = {
    .fmt = FMT_DELAY,       // "%0.3fS"
    .steps = Prot_D_step,
    .max_index = 4,         // 时间步进 5 个元素，max_index 为 4
    .init_index = 3,
    .scale = 1000.0,
    .min_val = 0.000,
    .max_val = 30.000,      // 欠流屏蔽可以设长一点
    .get_val = _get_ucp_warm,
    .set_val = _set_ucp_warm
};

/* --- UCP 延迟时间配置 --- */
const Protect_Item_Cfg_t CFG_UCP_DELAY = {
    .fmt = FMT_DELAY,
    .steps = Prot_D_step,
    .max_index = 4,
    .init_index = 3,
    .scale = 1000.0,
    .min_val = 0.000,
    .max_val = 10.000,
    .get_val = _get_ucp_d,
    .set_val = _set_ucp_d
};

/* --- Foldback Config --- */
const Protect_Item_Cfg_t CFG_FOLD_DELAY = {
    .fmt = FMT_DELAY,
    .steps = Prot_D_step,
    .max_index = 4,
    .init_index = 3,
    .scale = 1000.0,
    .min_val = 0.000,
    .max_val = 10.000,
    .get_val = _get_fold_d,
    .set_val = _set_fold_d
};
/* ----------------------------------------------------------------
    4. 最终 Handler (非常干净，只负责维护自己的 index)
   ---------------------------------------------------------------- */


// 现在的 Handler 只需要这一句：
void prot_ovp_v_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    // 同样传入 is_neg，确保直输时也能自动转负
    NumberInput_Process(7, _set_ovp_v,(&CFG_OVP_VOLT),0);
    protect_item_logic_core(e, &idx, &CFG_OVP_VOLT, false);
}

void prot_ovp_delay_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    NumberInput_Process(7, _set_ovp_d, (&CFG_OVP_DELAY), 0);
    protect_item_logic_core(e, &idx, &CFG_OVP_DELAY, false);
}

// === OCP (Over Current) ===
void prot_ocp_pos_i_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    NumberInput_Process(7, _set_ocp_pos_i, (&CFG_OCP_POS_I), 0);
    protect_item_logic_core(e, &idx, &CFG_OCP_POS_I, false);
}

void prot_ocp_neg_i_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    // 负向电流：is_neg 设为 1 和 true
    NumberInput_Process(7, _set_ocp_neg_i, (&CFG_OCP_NEG_I), 1);
    protect_item_logic_core(e, &idx, &CFG_OCP_NEG_I, true);
}

void prot_ocp_delay_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    NumberInput_Process(7, _set_ocp_d, (&CFG_OCP_DELAY), 0);
    protect_item_logic_core(e, &idx, &CFG_OCP_DELAY, false);
}

// === OPP (Over Power) ===
void prot_opp_pos_p_set_handler(lv_event_t * e) {
    static uint8_t idx = 1; 
    NumberInput_Process(7, _set_opp_pos_p, (&CFG_OPP_POS_P), 0);
    protect_item_logic_core(e, &idx, &CFG_OPP_POS_P, false);
}

void prot_opp_neg_p_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    // 负向功率：is_neg 设为 1 和 true
    NumberInput_Process(7, _set_opp_neg_p, (&CFG_OPP_NEG_P), 1);
    protect_item_logic_core(e, &idx, &CFG_OPP_NEG_P, true);
}

void prot_opp_delay_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    NumberInput_Process(7, _set_opp_d, (&CFG_OPP_DELAY), 0);
    protect_item_logic_core(e, &idx, &CFG_OPP_DELAY, false);
}

// === UVP (Under Voltage) ===
void prot_uvp_v_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    NumberInput_Process(7, _set_uvp_v, (&CFG_UVP_VOLT), 0);
    protect_item_logic_core(e, &idx, &CFG_UVP_VOLT, false);
}

void prot_uvp_warm_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    NumberInput_Process(7, _set_uvp_warm, (&CFG_UVP_WARM), 0);
    protect_item_logic_core(e, &idx, &CFG_UVP_WARM, false);
}

void prot_uvp_delay_set_handler(lv_event_t * e) {
    static uint8_t idx = 3;
    NumberInput_Process(7, _set_uvp_d, (&CFG_UVP_DELAY), 0);
    protect_item_logic_core(e, &idx, &CFG_UVP_DELAY, false);
}

// === UCP (Under Current) ===
void prot_ucp_pos_i_set_handler(lv_event_t * e) {
    static uint8_t idx = 3;
    NumberInput_Process(7, _set_ucp_pos_i, (&CFG_UCP_POS_I), 0);
    protect_item_logic_core(e, &idx, &CFG_UCP_POS_I, false);
}

void prot_ucp_neg_i_set_handler(lv_event_t * e) {
    static uint8_t idx = 3;
    // 负向欠流：is_neg 设为 1 和 true
    NumberInput_Process(7, _set_ucp_neg_i, (&CFG_UCP_NEG_I), 1);
    protect_item_logic_core(e, &idx, &CFG_UCP_NEG_I, true);
}

void prot_ucp_warm_set_handler(lv_event_t * e) {
    static uint8_t idx = 3;
    NumberInput_Process(7, _set_ucp_warm, (&CFG_UCP_WARM), 0);
    protect_item_logic_core(e, &idx, &CFG_UCP_WARM, false);
}

void prot_ucp_delay_set_handler(lv_event_t * e) {
    static uint8_t idx = 3;
    NumberInput_Process(7, _set_ucp_d, (&CFG_UCP_DELAY), 0);
    protect_item_logic_core(e, &idx, &CFG_UCP_DELAY, false);
}

// === Foldback ===
void prot_fold_delay_set_handler(lv_event_t * e) {
    static uint8_t idx = 1;
    NumberInput_Process(7, _set_fold_d, (&CFG_FOLD_DELAY), 0);
    protect_item_logic_core(e, &idx, &CFG_FOLD_DELAY, false);
}

//Foldback mode
/**
 * @brief Foldback 模式切换处理器
 */
#if 1
void prot_fold_mode_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);
    extern uint8_t protect_nav_level; // 引用你 Menu_Protect.c 里的层级变量

    // A. 进入编辑状态：当导航框架进入 Level 2 时，直接弹出下拉列表
    if(code == LV_EVENT_CLICKED) {
        if(!lv_dropdown_is_open(obj)) {
            lv_dropdown_open(obj);
        }
    }


    // B. 选中值改变：用户选择了 CC 或 CV
    if(code == LV_EVENT_VALUE_CHANGED) {
        uint16_t sel_id = lv_dropdown_get_selected(obj);
        IF_Power_Set_Fold_Mode((uint8_t)sel_id); // 写入硬件           
      //  lv_event_send(obj, LV_EVENT_FOCUSED, NULL);
    }

    // --- 情况 B：处理 ESC 退出焦点 ---
    if(code == LV_EVENT_KEY) {
        lv_key_t key = lv_event_get_key(e);
        if(key == LV_KEY_ESC || key == LV_KEY_ENTER) {
            // 无论列表开没开，只要按了 ESC，就强制退出当前的 selNode 状态
            Tree_UI_Sel_Exit();            
            // 还原高亮
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff0034), 0);
        }
    }
}

#endif


#if 0
void prot_fold_mode_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    // --- 1. 处理聚焦：由 Tree_UI_Sel_Enter 触发 ---
    if(code == LV_EVENT_FOCUSED) {
        // 变红高亮，滚动对齐。这里不弹出。
        lv_obj_set_style_text_color(obj, lv_color_hex(0xff0034), 0);
        lv_obj_scroll_to_view(obj, LV_ANIM_ON);
    }

    // --- 2. 关键修复：利用框架发送的 CLICKED 事件实现一键弹出 ---
    // 第一次按 Enter 时，框架会调用 Tree_UI_Sel_Enter，随后发出这个 CLICKED
    if(code == LV_EVENT_CLICKED) {
        if(!lv_dropdown_is_open(obj)) {
            lv_dropdown_open(obj);
        }
    }

    // --- 3. 处理选值改变：选完后要能立刻 UP/DOWN ---
    if(code == LV_EVENT_VALUE_CHANGED) {
        uint16_t sel_id = lv_dropdown_get_selected(obj);
        IF_Power_Set_Fold_Mode((uint8_t)sel_id);

        lv_dropdown_close(obj);
        // 选完直接退出编辑态，控制权还给导航框架
        Tree_UI_Sel_Exit(); 
        
        // 保持红色高亮
        lv_obj_set_style_text_color(obj, lv_color_hex(0xff0034), 0);
        lv_indev_wait_release(lv_indev_get_act());
    }

    // --- 4. 处理按键：主要用于 ESC 退出 ---
    if(code == LV_EVENT_KEY) {
        lv_key_t key = lv_event_get_key(e);
        if(key == LV_KEY_ESC) {
            if(lv_dropdown_is_open(obj)) {
                lv_dropdown_close(obj);
            } else {
                Tree_UI_Sel_Exit();
                lv_obj_set_style_text_color(obj, lv_color_hex(0xff0034), 0);
            }
        }
    }

    // --- 5. 失去焦点：变回原色 ---
    if(code == LV_EVENT_DEFOCUSED) {
        lv_obj_set_style_text_color(obj, lv_color_hex(0x67ff00), 0);
    }
}
#endif
/**
 * @brief 保护菜单全量 UI 刷新
 * @note 在菜单页面创建完成后调用，将结构体数据同步到屏幕
 */
void Menu_Protect_UI_Full_Sync(void) {
    // 1. 刷新数值类 (使用我们之前定义的 CFG 结构)
    // OVP
    Set_RefreshUI_Protect(ui.Menu_Protect_label_ovp_state_v_set, NULL, CFG_OVP_VOLT.fmt, CFG_OVP_VOLT.get_val() / CFG_OVP_VOLT.scale);
    Set_RefreshUI_Protect(ui.Menu_Protect_label_ovp_state_delay_set, NULL, CFG_OVP_DELAY.fmt, CFG_OVP_DELAY.get_val() / CFG_OVP_DELAY.scale);

    // OCP
    Set_RefreshUI_Protect(ui.Menu_Protect_label_ocp_state_pos_i_set, NULL, CFG_OCP_POS_I.fmt, CFG_OCP_POS_I.get_val() / CFG_OCP_POS_I.scale);
    Set_RefreshUI_Protect(ui.Menu_Protect_label_ocp_state_neg_i_set, NULL, CFG_OCP_NEG_I.fmt, fabs(CFG_OCP_NEG_I.get_val() / CFG_OCP_NEG_I.scale));
    Set_RefreshUI_Protect(ui.Menu_Protect_label_ocp_state_delay_set, NULL, CFG_OCP_DELAY.fmt, CFG_OCP_DELAY.get_val() / CFG_OCP_DELAY.scale);

    // OPP
    Set_RefreshUI_Protect(ui.Menu_Protect_label_opp_state_pos_w_set, NULL, CFG_OPP_POS_P.fmt, CFG_OPP_POS_P.get_val() / CFG_OPP_POS_P.scale);
    Set_RefreshUI_Protect(ui.Menu_Protect_label_opp_state_neg_w_set, NULL, CFG_OPP_NEG_P.fmt, fabs(CFG_OPP_NEG_P.get_val() / CFG_OPP_NEG_P.scale));
    Set_RefreshUI_Protect(ui.Menu_Protect_label_opp_state_delay_set, NULL, CFG_OPP_DELAY.fmt, CFG_OPP_DELAY.get_val() / CFG_OPP_DELAY.scale);

    // UVP
    Set_RefreshUI_Protect(ui.Menu_Protect_label_uvp_state_v_set, NULL, CFG_UVP_VOLT.fmt, CFG_UVP_VOLT.get_val() / CFG_UVP_VOLT.scale);
    Set_RefreshUI_Protect(ui.Menu_Protect_label_uvp_state_warm_set, NULL, CFG_UVP_WARM.fmt, CFG_UVP_WARM.get_val() / CFG_UVP_WARM.scale);
    Set_RefreshUI_Protect(ui.Menu_Protect_label_uvp_state_delay_set, NULL, CFG_UVP_DELAY.fmt, CFG_UVP_DELAY.get_val() / CFG_UVP_DELAY.scale);

    // UCP
    Set_RefreshUI_Protect(ui.Menu_Protect_label_ucp_state_i_pos_set, NULL, CFG_UCP_POS_I.fmt, CFG_UCP_POS_I.get_val() / CFG_UCP_POS_I.scale);
    Set_RefreshUI_Protect(ui.Menu_Protect_label_ucp_state_i_neg_set, NULL, CFG_UCP_NEG_I.fmt, fabs(CFG_UCP_NEG_I.get_val() / CFG_UCP_NEG_I.scale));
    Set_RefreshUI_Protect(ui.Menu_Protect_label_ucp_state_warm_set, NULL, CFG_UCP_WARM.fmt, CFG_UCP_WARM.get_val() / CFG_UCP_WARM.scale);
    Set_RefreshUI_Protect(ui.Menu_Protect_label_ucp_state_delay_set, NULL, CFG_UCP_DELAY.fmt, CFG_UCP_DELAY.get_val() / CFG_UCP_DELAY.scale);
    
    // FOLDBACK
    Set_RefreshUI_Protect(ui.Menu_Protect_label_foldback_delay_set, NULL, CFG_FOLD_DELAY.fmt, CFG_FOLD_DELAY.get_val() / CFG_FOLD_DELAY.scale);
    
   
    // 同步 Foldback 下拉框
    lv_dropdown_set_selected(ui.Menu_Protect_ddlist_foldback, IF_Power_Get_Fold_Mode());
    


    
}
