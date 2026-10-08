/*
 * TIM0_prog.c
 *
 * Created: 6/10/2026 8:32:59 PM
 *  Author: x13
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/InterruptVectorNum.h"
#include "TIM0_interface.h"
#include "TIM0_reg.h"


void(*TIM0_PTR[2])(void) = {null} ; 


void TIM0_voidInit(u8 mode )
 {
	 
	  /*SET Prescaler */
	  
	  TCCR0_REG&=0b11111000 ;
	  TCCR0_REG |=TIM0_PRESCALER ;
	
	
	switch(mode){
		
		case OV_MODE : 
		          /*1- select mode : Normal mode  */
		          
		          CLR_BIT(TCCR0_REG,3) ;
		          CLR_BIT(TCCR0_REG,6) ;
		     
		          /*Enable  TIM0 overflow interrupt */
		          
		          SET_BIT(TIMSK_REG,0) ; break;
				  
		case CTC_MODE :  
		            		  
		            /*1- select mode : Normal mode  */
		            
		            SET_BIT(TCCR0_REG,3) ;
		            CLR_BIT(TCCR0_REG,6) ;
		            
		            /*Enable  TIM0 overflow interrupt " PIE"  */
		            
		            SET_BIT(TIMSK_REG,1) ; break;
		               
					OCR0_REG = OCR_VAL ; break ;    
		
		
	}
	
	
	
}

void TIM0_voidSetCallBack(void(*ptr)(void) , u8 mode ) {
	
	      TIM0_PTR[mode] = ptr ; 
	
	
}

void TIM0_voidFatPWM(u8 duty) {
	
	 /*1- select mode : fast pwm   */
	 
	 SET_BIT(TCCR0_REG,3) ;
	 SET_BIT(TCCR0_REG,6) ;
	/* FAST PWM : non inverting mode */
	
	CLR_BIT(TCCR0_REG,4) ; 
	SET_BIT(TCCR0_REG,5) ; 
	
	/*SET prescaler */
	
	 TCCR0_REG&=0b11111000 ;
	 TCCR0_REG |=TIM0_PRESCALER ;
	 /* set OCR VA L */
	   /*
	   
	     DC = OCR / 2 ^ res     -- res : 8 bit  , dc 
	   
	   */
	
	        OCR0_REG =  duty *2.55 ; 
	
	
	
	}  // 50  80



ISR(TIMER0_OVF){
	
	
		TIM0_PTR[0]() ;

	
}
ISR(TIMER0_COMP){
	
	
	TIM0_PTR[1]() ;

	
}
