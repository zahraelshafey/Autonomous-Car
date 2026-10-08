/*
 * EXTI_prog.c
 *
 * Created: 5/13/2026 8:39:27 PM
 *  Author: fathi
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "EXTI_interface.h"
#include "EXTI_reg.h"


void (*EXTI_PTR[3])(void)={null} ;




void EXTI_voidInit(u8 copy_u8Num  , u8 copy_u8sense) {
	
	
	switch(copy_u8Num) {
		
		case  INT_0 : 
		              
					  if (copy_u8sense == LOW_LEVEL)
					  {
						  CLR_BIT(MCUCR_REG,0) ; 
						  CLR_BIT(MCUCR_REG,1) ;
						  
						  
					  }
					  else if (copy_u8sense == ANY_LOGICAL_CHANIG)
					  {
						  SET_BIT(MCUCR_REG,0) ;
						  CLR_BIT(MCUCR_REG,1) ;
					  }
					  else if (copy_u8sense ==FALLING_EDGE) {
						  
						  CLR_BIT(MCUCR_REG,0) ;
						  SET_BIT(MCUCR_REG,1) ;
					  }
					  else if (copy_u8sense == RISING_EDGE)
					  {
						  SET_BIT(MCUCR_REG,0) ;
						  SET_BIT(MCUCR_REG,1) ;
					  }
		
	  case INT_1 :   	      
			           if (copy_u8sense == LOW_LEVEL)
			           {
				           CLR_BIT(MCUCR_REG,2) ;
				           CLR_BIT(MCUCR_REG,3) ;  
			           }
			           else if (copy_u8sense == ANY_LOGICAL_CHANIG)
			           {
				           SET_BIT(MCUCR_REG,2) ;
				           CLR_BIT(MCUCR_REG,3) ;
			           }
			           else if (copy_u8sense ==FALLING_EDGE) {
				           
				           CLR_BIT(MCUCR_REG,2) ;
				           SET_BIT(MCUCR_REG,3) ;
			           }
			           else if (copy_u8sense == RISING_EDGE)
			           {
				           SET_BIT(MCUCR_REG,2) ;
				           SET_BIT(MCUCR_REG,3) ;
			           }
			           
	  case INT_2 : 
	                 if (copy_u8sense == FALLING_EDGE)
	                 { 
						  CLR_BIT(MCUCSR_REG,6)  ; 
	                 }
					 else if (copy_u8sense ==RISING_EDGE)
					 {
						 SET_BIT(MCUCSR_REG,6) ; 
					 }
	}
}



void EXTI0_voidEnable(void) {
	
	SET_BIT(GICR_REG,6) ; 
	
}
void EXTI0_voidDisable(void) {
	
	CLR_BIT(GICR_REG,6) ; 
	

}


void EXTI1_voidEnable(void) {
	SET_BIT(GICR_REG,7) ;
	
	
}
void EXTI1_voidDisable(void) {
	CLR_BIT(GICR_REG,7) ;
	
}


void EXTI2_voidEnable(void) {
	
	SET_BIT(GICR_REG,5) ; 
}
void EXTI2_voidDisable(void) {
	CLR_BIT(GICR_REG,5) ;
	
}




void EXTI_voidSetCallBack(void(*ptr)(void) , u8 copy_u8Num ){
	
                EXTI_PTR[copy_u8Num] = ptr ; 
}







void __vector_1( void )__attribute__((signal));
void __vector_1(void){
	
	
  EXTI_PTR[0]() ; 
}


void __vector_2( void )__attribute__((signal));
void __vector_2(void){
	
	
	EXTI_PTR[1]() ;
}


void __vector_3( void )__attribute__((signal));
void __vector_3(void){
	
	
	EXTI_PTR[2]() ;
}