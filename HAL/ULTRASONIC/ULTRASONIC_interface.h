/*
 * ULTRASONIC_interface.h
 *
 * Created: 9/27/2026 7:56:58 PM
 *  Author: zahra ahmed elshafey
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

 #include "../../LIB/STD_TYPE.h"

void ULTRASONIC_voidInit(void);
void ULTRASONIC_voidTrigger(void);
u8   ULTRASONIC_u8IsDistanceReady(void);
u16  ULTRASONIC_u16GetDistance(void);
#endif /* ULTRASONIC_INTERFACE_H_ */