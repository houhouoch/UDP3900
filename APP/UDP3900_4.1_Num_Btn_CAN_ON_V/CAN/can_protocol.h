#ifndef _CAN_PROTOCOL_H_
#define _CAN_PROTOCOL_H_

#include "main.h"

// 导出函数：发送电源控制指令

void Power_System_Start_Sequence(void);
void Power_System_Stop_Sequence(void);

void CAN_Protocol_Send_Control_Float(uint16_t action, float value);



#endif
