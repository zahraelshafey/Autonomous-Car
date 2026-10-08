 /*
 * TIMER1_prog.c
 *
 * Created: 8/26/2026 2:34:17 AM
 *  Author: zahra ahmed elshafey
 */ 
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/InterruptVectorNum.h"
#include "../DIO/DIO_interface.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"
#include "TIMER1_reg.h"

static void (*TIMER1_CallBackPtr)(void) = 0 ;

/* ---------------- ICU ---------------- */

void TIMER1_voidInit(u8 Copy_u8EdgeType)
{
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN6, INPUT);   // PD6 = ICP1 = Echo

	TIMER1_voidSetCaptureEdge(Copy_u8EdgeType);

	SET_BIT(TIMSK_REG, TICIE1_BIT);                  // enable input capture interrupt

	TCCR1B_REG &= 0xF8;
	TCCR1B_REG |= 0b011;                             // prescaler = 64
}

void TIMER1_voidSetCaptureEdge(u8 Copy_u8EdgeType)
{
	if(Copy_u8EdgeType == TIMER1_RISING_EDGE)
		SET_BIT(TCCR1B_REG, ICES1_BIT);
	else
		CLR_BIT(TCCR1B_REG, ICES1_BIT);
}

u16 TIMER1_u16GetInputCaptureValue(void)
{
	return ICR1_REG;
}

void TIMER1_voidSetCallBack(void(*Copy_PtrFunc)(void))
{
	TIMER1_CallBackPtr = Copy_PtrFunc;
}

/* ---------------- Fast PWM (servo) ---------------- */

void TIMER1_voidFastPWMInit(void)
{
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN4, OUTPUT);  // PD4 = OC1B = servo signal

	SET_BIT(TCCR1A_REG, WGM10_BIT);                  // WGM13:10 = 1111
	SET_BIT(TCCR1A_REG, WGM11_BIT);                  // = Fast PWM, TOP = OCR1A
	SET_BIT(TCCR1B_REG, WGM12_BIT);
	SET_BIT(TCCR1B_REG, WGM13_BIT);

	SET_BIT(TCCR1A_REG, COM1B1_BIT);                 // non-inverting on OC1B

	OCR1A_REG = 4999;                                // period = 5000 ticks * 4us = 20ms

	TCCR1B_REG &= 0xF8;
	TCCR1B_REG |= 0b011;                             // prescaler = 64
}

void TIMER1_voidSetDutyOCR1B(u16 Copy_u16Val)
{
	OCR1B_REG = Copy_u16Val;
}

/* ---------------- ISR ---------------- */

ISR(TIMER1_CAPT)
{
	if(TIMER1_CallBackPtr != 0)
	{
		TIMER1_CallBackPtr();
	}
}