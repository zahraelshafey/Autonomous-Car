/*
 * TIMER1_reg.h
 *
 * Created: 9/26/2026 2:31:38 AM
 *  Author: zahra ahmed elshafey
 */ 
#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

#define TCCR1A_REG      *((volatile u8*)0x4F)
#define TCCR1B_REG      *((volatile u8*)0x4E)
#define TCNT1_REG       *((volatile u16*)0x4C)
#define OCR1A_REG       *((volatile u16*)0x4A)
#define OCR1B_REG       *((volatile u16*)0x48)
#define ICR1_REG        *((volatile u16*)0x46)
#define TIMSK_REG       *((volatile u8*)0x59)
#define TIFR_REG        *((volatile u8*)0x58)

#define COM1B1_BIT      5
#define WGM11_BIT       1
#define WGM10_BIT       0

#define ICNC1_BIT       7
#define ICES1_BIT       6
#define WGM13_BIT       4
#define WGM12_BIT       3
#define CS12_BIT        2
#define CS11_BIT        1
#define CS10_BIT        0

#define TICIE1_BIT      5
#define ICF1_BIT        5

#endif /* TIMER1_REG_H_ */