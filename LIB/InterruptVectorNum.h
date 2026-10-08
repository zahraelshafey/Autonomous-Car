/*
 * InterruptVectorNum.h
 *
 * Created: 6/15/2026 8:28:07 PM
 *  Author: x13
 */ 


#ifndef INTERRUPTVECTORNUM_H_
#define INTERRUPTVECTORNUM_H_



#define  ISR(__vector_NUM)        void __vector_NUM( void )__attribute__((signal));\
                                  void __vector_NUM(void)


#define  _INT0             __vector_1
#define  _INT1             __vector_2
#define  _INT2             __vector_3
#define TIMER1_CAPT        __vector_6
#define TIMER1_COMPA       __vector_7
#define TIMER0_OVF         __vector_11
#define TIMER0_COMP        __vector_10
 






#endif /* INTERRUPTVECTORNUM_H_ */