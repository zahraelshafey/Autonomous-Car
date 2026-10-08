/*
 * LCD_prog.c
 *
 * Created: 4/15/2026 7:49:32 PM
 *  Author: fathi
 */ 
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#define F_CPU 16000000UL 
#include<util/delay.h>


#define  LCD_PINS       4 


static void LCD_voidSHData(u8 copy_u8data){
	
	u8 LCD_pins[LCD_PINS] = {LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN} ; 
	 u8 Loc_i=0 ; 
	 
	 for (Loc_i =0 ; Loc_i < LCD_PINS ; Loc_i++ )
	 {
		  DIO_voidSetPinVal(LCD_DPORT,LCD_pins[Loc_i],GET_BIT(copy_u8data,Loc_i)) ; 
		  
	 }
}



static void LCD_voidSendEnablePulse(void){
		 /* send Enable */
		 
		 DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,HIGH) ;
		 _delay_ms(2) ;
		 DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,LOW) ;
}

void LCD_voidInit(void) {
	
	 DIO_voidSetPortDir(LCD_CPORT,LCD_C_DIR) ;
	 DIO_voidSetPortDir(LCD_DPORT,LCD_D_DIR) ;
	 
	 
	 
	 _delay_ms(40);
	 
	  /* set function set */
	    #if LCD_MODE == LCD_8BIT_MODE
		LCD_voidSendCommand(0x38) ; 
		
		#elif LCD_MODE  == LCD_4BIT_MODE
		 
		  LCD_voidSHData(0b0010) ; 
		  LCD_voidSendEnablePulse() ; 
		  
		  LCD_voidSHData(0b0010) ;
		  LCD_voidSendEnablePulse() ;
		  LCD_voidSHData(0b1000) ;
		  LCD_voidSendEnablePulse() ;
		  
		#endif 	
	  /*dispaly on /off control */ 
	  LCD_voidSendCommand(0x0C) ; 
	    
	 /* clr lcd */
	 LCD_voidSendCommand(1) ; 

}

void LCD_voidSendCommand(u8 copy_u8command) {
	
	 /* clr rs pin to send command  */
	 DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,LOW) ; 
	 /* clr  RW  pin to  write  command  */
	 
	 DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW) ; 
	 
	 /* Send Command */
	 
	  #if LCD_MODE == LCD_8BIT_MODE
	 DIO_voidSetPortVal(LCD_DPORT,copy_u8command) ; 
	 LCD_voidSendEnablePulse() ; 
	 
	 #elif LCD_MODE ==LCD_4BIT_MODE 
	                                                    
	  LCD_voidSHData(copy_u8command>>4) ; 
	  LCD_voidSendEnablePulse() ; 
	  LCD_voidSHData(copy_u8command) ; 
	  LCD_voidSendEnablePulse() ;
	  #endif 
	 
	 
	 
 
}

void LCD_voidSendData(u8 copy_u8data) {
	
	
 /* clr rs pin to send data  */
 DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,HIGH) ;
 /* clr  RW  pin to  write  command  */
 
 DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW) ;
 
 
  #if LCD_MODE == LCD_8BIT_MODE
  DIO_voidSetPortVal(LCD_DPORT,copy_u8data) ;
  LCD_voidSendEnablePulse() ;
  
  #elif LCD_MODE ==LCD_4BIT_MODE
  
  LCD_voidSHData(copy_u8data>>4) ;
  LCD_voidSendEnablePulse() ;
  LCD_voidSHData(copy_u8data) ;
  LCD_voidSendEnablePulse() ;
  #endif
	
	
	
}



void LCD_voidSendString(s8 * str) {
	
	u8 i=0 ; 
	
	 while(str[i] != nul){
		 
		 LCD_voidSendData(str[i]) ; 
		 i++ ; 
		 
	 }

}


void LCD_voidGotoXY(u8 copy_u8x , u8 copy_u8y) {
	
	u8 LOC_u8ddramAddress=0 ; 
	
	 LOC_u8ddramAddress = (copy_u8x + (copy_u8y*0x40 )); 
	            
	 
	 /*set ddram */
	  
	  SET_BIT(LOC_u8ddramAddress,7) ; 
	  
	  LCD_voidSendCommand(LOC_u8ddramAddress) ; 
	
}


void LCD_voidDrawData(u8 *data , u8 pattern , u8 copy_u8x , u8 copy_u8y) {
	
	   u8 CGRAM_Address= pattern * 8 ; 
	   u8 i= 0 ; 
	   /* set CGRAM */
	    CLR_BIT(CGRAM_Address,7) ; 
		SET_BIT(CGRAM_Address,6) ; 
		LCD_voidSendCommand(CGRAM_Address) ; 
		/*Send data  */
	    for (i=0 ; i<8;i++)
	    {
			LCD_voidSendData(data[i]) ; 
	    }
     LCD_voidGotoXY(copy_u8x,copy_u8y) ; 
	 
	 LCD_voidSendData(pattern) ; 
	
}
void LCD_voidSendNumber(u32 copy_32num) {
	s8 i=0 ;
	
	u8 array[10] ;
	
	if (copy_32num ==0)
	{
		LCD_voidSendData('0') ;
		
		return ;
	}
	
	for (i=0 ; copy_32num !=0 ; i++)
	{
		array[i]=copy_32num % 10 +48 ;
		
		copy_32num /=10 ;
		
	}
	i-- ;  
	while( i >=0){	
		LCD_voidSendData(array[i]) ;
		i-- ;}
}