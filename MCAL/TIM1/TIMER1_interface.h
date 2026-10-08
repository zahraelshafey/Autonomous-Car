 /*
 * TIMER1_interface.h
 *
 * Created: 8/26/2026 2:33:22 AM
 *  Author: zahra ahmed elshafey
 */ 
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#include "../../LIB/STD_TYPE.h"
#include "TIMER1_config.h"

/* ICU (ultrasonic echo) */
void TIMER1_voidInit(u8 Copy_u8EdgeType);
void TIMER1_voidSetCaptureEdge(u8 Copy_u8EdgeType);
u16  TIMER1_u16GetInputCaptureValue(void);
void TIMER1_voidSetCallBack(void(*Copy_PtrFunc)(void));

/* Fast PWM (servo on PD4 / OC1B) */
void TIMER1_voidFastPWMInit(void);
void TIMER1_voidSetDutyOCR1B(u16 Copy_u16Val);

#endif /* TIMER1_INTERFACE_H_ */