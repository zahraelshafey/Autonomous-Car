/*
 * LCD_interface.h
 *
 * Created: 4/15/2026 7:48:42 PM
 *  Author: fathi
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



/* LCD MODE */

#define  LCD_4BIT_MODE           0 
#define  LCD_8BIT_MODE           1 


#define LCD_MODE        LCD_4BIT_MODE




void LCD_voidInit(void) ; 

void LCD_voidSendCommand(u8 copy_u8command) ; 

void LCD_voidSendData(u8 copy_u8data) ; 


void LCD_voidSendString(s8 * str) ; 

void LCD_voidGotoXY(u8 copy_u8x , u8 copy_u8y) ; 

void LCD_voidDrawData(u8 *data , u8 pattern , u8 copy_u8x , u8 copy_u8y) ; 

void LCD_voidSendNumber(u32 copy_32num) ; 
#endif /* LCD_INTERFACE_H_ */