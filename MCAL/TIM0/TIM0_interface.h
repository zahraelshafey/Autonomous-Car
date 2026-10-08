/*
 * TIM0_interface.h
 *
 * Created: 6/10/2026 8:32:44 PM
 *  Author: x13
 */ 


#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_


/* TIM0  prescaler */


#define  TIM0_NO_PRESCALER            1
#define  TIM0_8_PRESCALER             2
#define  TIM0_64_PRESCALER            3
#define  TIM0_256_PRESCALER           4
#define  TIM0_1024_PRESCALER          5

/* select tim0 prescaler */

#define  TIM0_PRESCALER        	TIM0_1024_PRESCALER

/*TIMER0 MODES */

#define  OV_MODE        0 
#define  CTC_MODE       1 

/*SET OCR VAL */

#define  OCR_VAL        250 
void TIM0_voidInit(u8 mode ) ; 


void TIM0_voidSetCallBack(void(*ptr)(void) , u8 mode ) ; 



void TIM0_voidFatPWM(u8 duty) ;  // 50  80 


#endif /* TIM0_INTERFACE_H_ */