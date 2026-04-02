#ifndef POWER_INTERFACE_H
#define POWER_INTERFACE_H
#include "main.h"
#include "can.h"
typedef struct {
    // --- 输出基本设置 ---
    double volt_set;            // 输出电压设置值 (V)
    double curr_set;            // 输出正向电流设置值 (A)
    double curr_set_neg;        // 输出负向电流设置值 (A)
    double ResIn_set;           // 内阻模拟设置 (Ω)
    uint8_t onoff;              // 总输出开关状态 (0:OFF, 1:ON)

    // --- OVP (过压保护) ---
    double ovp_set;             // 过压保护阈值 (V)
    uint8_t ovp_onoff;          // 过压保护开关
    int16_t ovp_delayTime;      // 过压触发延迟 (ms)


    // --- OCP (过流保护) ---
    double ocp_set;             // 过流保护阈值 - 正向 (A)
    double ocp_set_neg;         // 过流保护阈值 - 负向 (A) 
    uint8_t ocp_onoff;          // 过流保护开关
    int16_t ocp_delayTime;      // 过流触发延迟 (ms)

    // --- OPP (过功率保护) ---
    double opp_set;         // 正向功率保护 (W)
    double opp_set_neg;     // 负向功率保护 (W) 【新增】
    uint8_t opp_onoff;      // OPP 开关
    int16_t opp_delayTime;  // OPP 延迟 (ms)

    // --- UVP (欠压保护) ---
    double uvp_set;             // 欠压保护阈值 (V)
    uint8_t uvp_onoff;          // 欠压保护开关
    int16_t uvp_warmTime;       // 欠压热机/启动屏蔽时间 (ms)
    int16_t uvp_delayTime;      // 欠压触发延迟 (ms)

    // --- UCP (欠流保护) ---
    double ucp_set;             // 欠流保护阈值 - 正向 (A)
    double ucp_set_neg;         // 欠流保护阈值 - 负向 (A) 【补全】
    uint8_t ucp_onoff;          // 欠流保护开关
    int16_t ucp_warmTime;       // 欠流热机/启动屏蔽时间 (ms)
    int16_t ucp_delayTime;      // 欠流触发延迟 (ms)

    // --- Foldback (折返保护) ---
    uint8_t fold_onoff;         // 折返保护总开关
    uint8_t fold_mode;          // 折返模式 (0: CC-Fold, 1: CV-Fold)
    int16_t fold_delayTime;     // 折返保护延迟 (ms)

    // --- 电源斜率与动态特性 ---
    uint8_t SlewRate_Mode;      // 斜率模式开关
    float VSR_Up;               // 电压上升斜率 (V/s)
    float VSR_Down;             // 电压下降斜率 (V/s)
    float ISR_Up;               // 电流上升斜率 (A/s)
    float ISR_Down;             // 电流下降斜率 (A/s)

    // --- 系统运行模式 ---
    uint8_t powerMode;          // 电源工作模式 (CV/CC/CP等)
    uint8_t ac_down;            // 掉电检测处理 (0:Stop, 1:Last)
    uint8_t power_on;           // 上电输出策略
    uint8_t eLoad;              // 泄放负载/电子负载功能开关状态

    // --- 其他保护与监控 ---
    int16_t updateRate;         // UI或通讯数据刷新率
    int16_t otp_Temperature;    // 过温保护阈值设置 (°C)
    int16_t on_delayTime;       // 启动输出延时 (ms)
    int16_t off_delayTime;      // 关闭输出延时 (ms)

    // --- 系统底层与网络参数 ---
    uint8_t lock;               // 面板锁定状态
    uint8_t userGroup;          // 当前用户预设组
    uint8_t slave_ID;           // 从机/多机并联通讯ID
    uint8_t brightness;         // 屏幕亮度等级 (0-100)
    uint8_t language;           // 系统语言选择
    uint8_t beeper_en;          // 蜂鸣器开关
    uint8_t remoteLock;         // 远程控制自动上锁
    uint8_t dhcp_en;            // 网络参数是否启用DHCP
    uint8_t ip[4 + 1];          // 当前IP地址
    uint8_t gatewate[4 + 1];    // 网关
    uint8_t netmask[4 + 1];     // 子网掩码
    uint8_t mac[6 + 1];         // MAC地址 (只读)
    uint16_t scpiPort;          // SCPI 通讯端口号 (默认 5025)

    // --- 调试与补偿参数 ---
    float senseVolt;            // 远端采样电压补偿值 (V)
    int8_t maxFan;              // 风扇最大转速限制 (Debug)
    int8_t zeroCurrent_autoEn;  // 自动校准零位电流开关
    uint32_t localCookieID;     // 配置唯一性校验ID

    char multCH_ModelName[64];  // 设备/通道型号名称
    uint8_t canGroup;           // CAN通讯逻辑分组
    uint16_t reserve;           // 字节对齐预留
    uint16_t crc;               // 参数保存校验和
} OutSet_Def;



typedef struct {
    OutSet_Def outSet;
    uint8_t workMode;
    struct {
        uint8_t powerID;
        uint8_t powerChannels;

        uint8_t canUpdata_event;
        uint8_t syncRequest;
        uint8_t setchannged;    //用于保存
        uint8_t groupChannged;  //组参数保存
        uint8_t webchannged;    //网页密码保存
        uint8_t netApply;       //网络设置保存

        uint64_t runTime_ms;
        //输出AD采集
        double volt_adc;
        double curr_sum_adc;
        double curr_front_adc;  //前面板输出电流
        //实际输出
        double volt_read;
        double volt_drv_read;
        double curr_read;
        double power_read;
        #if 0
        //滤波后
        double volt_read;
        double curr_read;
        double power_read;
        #endif



        double volt_read_total;
        double curr_read_total;
        double power_read_total;
        //校准状态
        uint8_t voltCalib_state;
        uint8_t currCalib_state;
        //
        uint8_t powerCount;
        uint8_t powerType;
        //
        uint8_t voltCalib_Count;
        uint8_t voltDrvCalib_Count;
        uint8_t currCalib_Count;
        //
        float voltage_step;
        float current_step;
        //
        uint8_t dhcp_en;            //DHCP
        uint8_t ip[4 + 1];          //IP
        uint8_t gatewate[4 + 1];    //网关地址
        uint8_t netmask[4 + 1];     //子网掩码

        uint32_t cookieID;
    } Read;

    struct {
        int16_t temp_ext_1;     //模组1温度
        int16_t temp_ext_2;     //模组2温度
        int16_t temp_ext_3;     //模组3温度
        int16_t temp_ext_4;     //模组4温度
        int16_t temp_ext_5;     //模组5温度
        int16_t temp_pcb;       //PCB温度
    } Temperature;

    union {
        uint64_t byte;
        struct {
            uint8_t Power_Link: 1;
            uint8_t Sample_Ready: 1;
            uint8_t CAN: 1;
            uint8_t USB_Host: 1;
            uint8_t USB_Device: 1;
            uint8_t LAN_Linked: 1;
            uint8_t LOCK: 1;
            uint8_t Remote: 1;
            uint8_t Web: 1;
            uint8_t Socket: 1;
            uint8_t USB: 1;
            uint8_t LAN_10M: 1;
            uint8_t LAN_100M: 1;
            uint8_t LAN_Tx: 1;
            uint8_t LAN_Rx: 1;
            uint8_t SDRAM: 1;
            uint8_t LAN_DP83848: 1;
            uint8_t LAN_LAN8720: 1;
            uint8_t zeroCurr: 1;

            uint8_t eeprom_setting_lost: 1;
            uint8_t network_init_failed: 1;
            uint8_t flash_init_failed: 1;

        } bits;
    } StateBar;


} PowerInfo_t;

extern PowerInfo_t PowerInfo;

void Power_Param_Default_Init(void);

/* ----------------------------------------------------------------
    底层函数接口 (由 UI 逻辑或 SCPI 通讯层调用)
   ---------------------------------------------------------------- */
//锁
void UI_IF_Power_Set_Lock(uint8_t state);

//输出总开关
void IF_Power_Set_OutOnOff(uint8_t state);
uint8_t IF_Power_Get_OutOnOff(void);

// --- 0. 基本输出设置 ---
float   IF_Power_Get_OutVolt(void);
void    IF_Power_Set_OutVolt(float value);

float   IF_Power_Get_OutCurr(void);
void    IF_Power_Set_OutCurr(float value);

float   IF_Power_Get_OutCurr_Neg(void);
void    IF_Power_Set_OutCurr_Neg(float value);

uint8_t IF_Power_Get_OutState(void);
void    IF_Power_Set_OutState(uint8_t state);

// --- 1. OVP (过压保护) ---
float   IF_Power_Get_OVP_Volt(void);
void    IF_Power_Set_OVP_Volt(float value);

uint8_t IF_Power_Get_OVP_State(void);
void    IF_Power_Set_OVP_State(uint8_t state);

int16_t IF_Power_Get_OVP_Delay(void);
void    IF_Power_Set_OVP_Delay(int16_t value_ms);

// --- 2. OCP (过流保护) ---
// --- 正向 OCP ---
float   IF_Power_Get_OCP_Pos_Curr(void);
void    IF_Power_Set_OCP_Pos_Curr(float value);

// --- 负向 OCP ---
float   IF_Power_Get_OCP_Neg_Curr(void);
void    IF_Power_Set_OCP_Neg_Curr(float value);

// --- OCP 延迟与开关 ---
uint8_t IF_Power_Get_OCP_State(void);
void    IF_Power_Set_OCP_State(uint8_t state);

int16_t IF_Power_Get_OCP_Delay(void);
void    IF_Power_Set_OCP_Delay(int16_t value_ms);

/* ----------------------------------------------------------------
    3. OPP (Over Power Protection) - 接口声明
   ---------------------------------------------------------------- */

// --- 正向 OPP 阈值 ---
float   IF_Power_Get_OPP_Pos_Power(void);
void    IF_Power_Set_OPP_Pos_Power(float value);

// --- 负向 OPP 阈值 ---
float   IF_Power_Get_OPP_Neg_Power(void);
void    IF_Power_Set_OPP_Neg_Power(float value);

// --- OPP 开关与延迟 ---
uint8_t IF_Power_Get_OPP_State(void);
void    IF_Power_Set_OPP_State(uint8_t state);

int16_t IF_Power_Get_OPP_Delay(void);
void    IF_Power_Set_OPP_Delay(int16_t value_ms);

/* ----------------------------------------------------------------
    4. UVP (Under Voltage Protection) - 欠压保护
   ---------------------------------------------------------------- */

/** @brief UVP 阈值 (V) */
float   IF_Power_Get_UVP_Volt(void);
void    IF_Power_Set_UVP_Volt(float value);

/** @brief UVP 开关状态 (0:OFF, 1:ON) */
uint8_t IF_Power_Get_UVP_State(void);
void    IF_Power_Set_UVP_State(uint8_t state);

/** @brief UVP 启动屏蔽时间 (ms) */
int16_t IF_Power_Get_UVP_WarmTime(void);
void    IF_Power_Set_UVP_WarmTime(int16_t value_ms);

/** @brief UVP 触发延迟时间 (ms) */
int16_t IF_Power_Get_UVP_Delay(void);
void    IF_Power_Set_UVP_Delay(int16_t value_ms);


/* ----------------------------------------------------------------
    5. UCP (Under Current Protection) - 欠流保护
   ---------------------------------------------------------------- */

/** @brief UCP 正向阈值 (A) */
float   IF_Power_Get_UCP_Pos_Curr(void);
void    IF_Power_Set_UCP_Pos_Curr(float value);

/** @brief UCP 负向阈值 (A) */
float   IF_Power_Get_UCP_Neg_Curr(void);
void    IF_Power_Set_UCP_Neg_Curr(float value);

/** @brief UCP 开关状态 (0:OFF, 1:ON) */
uint8_t IF_Power_Get_UCP_State(void);
void    IF_Power_Set_UCP_State(uint8_t state);

/** @brief UCP 启动屏蔽时间 (ms) */
int16_t IF_Power_Get_UCP_WarmTime(void);
void    IF_Power_Set_UCP_WarmTime(int16_t value_ms);

/** @brief UCP 触发延迟时间 (ms) */
int16_t IF_Power_Get_UCP_Delay(void);
void    IF_Power_Set_UCP_Delay(int16_t value_ms);

// --- 6. Foldback (折返保护) ---
uint8_t IF_Power_Get_Foldback_State(void);
void    IF_Power_Set_Foldback_State(uint8_t state);

uint8_t IF_Power_Get_Foldback_Mode(void);
void    IF_Power_Set_Foldback_Mode(uint8_t mode);

int16_t IF_Power_Get_Foldback_Delay(void);
void    IF_Power_Set_Foldback_Delay(int16_t value_ms);

uint8_t IF_Power_Get_Fold_Mode(void);
void IF_Power_Set_Fold_Mode(uint8_t mode);

#endif

