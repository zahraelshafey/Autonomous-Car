/*
 * SERVO_prog.c
 *
 *  Author: zahra ahmed elshafey
 */ 
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/TIM1/TIMER1_interface.h"
#include "SERVO_config.h"
#include "SERVO_interface.h"

void SERVO_voidInit(void)
{
	TIMER1_voidFastPWMInit();
	SERVO_voidSetAngle(0);
}

void SERVO_voidSetAngle(s8 Copy_s8Angle)
{
	if(Copy_s8Angle < SERVO_MIN_ANGLE) Copy_s8Angle = SERVO_MIN_ANGLE;
	if(Copy_s8Angle > SERVO_MAX_ANGLE) Copy_s8Angle = SERVO_MAX_ANGLE;

	u16 Loc_u16Duty = SERVO_CENTER_DUTY +
	    ((s16)Copy_s8Angle * (SERVO_MAX_DUTY - SERVO_CENTER_DUTY)) / SERVO_MAX_ANGLE;

	TIMER1_voidSetDutyOCR1B(Loc_u16Duty);
}