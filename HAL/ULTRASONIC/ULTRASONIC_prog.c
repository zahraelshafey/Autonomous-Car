/*
 * ULTRASONIC_prog.c
 *
 * Created: 9/27/2026 7:58:14 PM
 *  Author: zahra ahmed elshafey
 */ 
#define F_CPU 16000000UL
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIM1/TIMER1_interface.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_interface.h"

#define TIMER1_PERIOD_TICKS   5000   /* Timer1 counts 0..4999 (OCR1A = 4999) */

static volatile u16 g_u16RisingVal  = 0;
static volatile u16 g_u16FallingVal = 0;
static volatile u8  g_u8State       = 0;   // 0 = waiting for rising edge, 1 = waiting for falling edge
static volatile u8  g_u8DataReady   = 0;

static void ULTRASONIC_voidCaptureHandler(void)
{
	if(g_u8State == 0)
	{
		g_u16RisingVal = TIMER1_u16GetInputCaptureValue();
		TIMER1_voidSetCaptureEdge(TIMER1_FALLING_EDGE);
		g_u8State = 1;
	}
	else
	{
		g_u16FallingVal = TIMER1_u16GetInputCaptureValue();
		TIMER1_voidSetCaptureEdge(TIMER1_RISING_EDGE);
		g_u8State = 0;
		g_u8DataReady = 1;
	}
}

void ULTRASONIC_voidInit(void)
{
	DIO_voidSetPinDir(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, OUTPUT);
	DIO_voidSetPinVal(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, LOW);

	TIMER1_voidInit(TIMER1_RISING_EDGE);
	TIMER1_voidSetCallBack(ULTRASONIC_voidCaptureHandler);
}

void ULTRASONIC_voidTrigger(void)
{
	DIO_voidSetPinVal(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, HIGH);
	_delay_us(10);
	DIO_voidSetPinVal(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, LOW);
}

u8 ULTRASONIC_u8IsDistanceReady(void)
{
	return g_u8DataReady;
}

u16 ULTRASONIC_u16GetDistance(void)
{
	u16 Loc_u16Diff;
	u32 Loc_u32TimeUs;

	if(g_u16FallingVal >= g_u16RisingVal)
	{
		Loc_u16Diff = g_u16FallingVal - g_u16RisingVal;
	}
	else
	{
		/* timer wrapped from 4999 back to 0 between the two edges */
		Loc_u16Diff = (TIMER1_PERIOD_TICKS - g_u16RisingVal) + g_u16FallingVal;
	}

	Loc_u32TimeUs = (u32)Loc_u16Diff * 4;   // 1 tick = 4us

	g_u8DataReady = 0;

	return (u16)(Loc_u32TimeUs / 58);       // cm
}