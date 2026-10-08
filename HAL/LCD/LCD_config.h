 /*
 * LCD_config.h
 *
 * Created: 9/21/2026 1:49:23 AM
 *  Author: zahra ahmed elshafey
 */ 
 
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define  LCD_C_DIR        0x03
#define  LCD_D_DIR        0xf0

/* LCD Control pins */

#define  LCD_CPORT    DIO_PORTB

#define LCD_RS_PIN    DIO_PIN1
#define LCD_RW_PIN    DIO_PIN5
#define LCD_EN_PIN    DIO_PIN0


/*LCD Data pins */

#if LCD_MODE  == LCD_8BIT_MODE

#define  LCD_DPORT      DIO_PORTA

#elif LCD_MODE == LCD_4BIT_MODE

#define  LCD_DPORT     DIO_PORTA

#define  LCD_D4_PIN    DIO_PIN4
#define  LCD_D5_PIN    DIO_PIN5
#define  LCD_D6_PIN    DIO_PIN6
#define  LCD_D7_PIN    DIO_PIN7

#endif

#endif /* LCD_CONFIG_H_ */