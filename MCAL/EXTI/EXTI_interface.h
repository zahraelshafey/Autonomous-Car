/*
 * EXTI_interface.h
 *
 * Created: 5/13/2026 8:39:41 PM
 *  Author: fathi
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


/*external interrupt pins */

#define  INT_0           0
#define  INT_1           1 
#define  INT_2           2

/* EXTI  sense control  */

#define  LOW_LEVEL             0 
#define  ANY_LOGICAL_CHANIG    1 
#define  FALLING_EDGE          2 
#define  RISING_EDGE           3 



void EXTI_voidInit(u8 copy_u8Num  , u8 copy_u8sense) ; 


void EXTI0_voidEnable(void) ; 
void EXTI0_voidDisable(void) ;

void EXTI1_voidEnable(void) ;
void EXTI1_voidDisable(void) ;


void EXTI2_voidEnable(void) ;
void EXTI2_voidDisable(void) ;


void EXTI_voidSetCallBack(void(*ptr)(void) , u8 copy_u8Num );

#endif /* EXTI_INTERFACE_H_ */