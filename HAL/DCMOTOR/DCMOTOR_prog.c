/*
 * DCMOTOR_prog.c
 *
 * Created: 9/5/2026 5:49:06 AM
 *  Author: zahra ahmed elshafey
 */ 
/*
 * DCMOTOR_prog.c
 */
#include "../../LIB/BIT_MATH.h"                     
#include "../../LIB/STD_TYPE.h"                    
#include "../../MCAL/DIO/DIO_interface.h"          
       

#include "DCMOTOR_config.h"                        
#include "DCMOTOR_interface.h"                      

 
void DCMOTOR_voidInit(void)
{
    
    DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A1_PIN, OUTPUT);       // motor 1 direction pin A as output
    DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A2_PIN, OUTPUT);       // motor 1 direction pin B as output
    DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A3_PIN, OUTPUT);       // motor 2 direction pin A as output
    DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A4_PIN, OUTPUT);       // motor 2 direction pin B as output

                                              
}

/*
 * Both motors spin forward at the given speed
 */
void DCMOTOR_voidForward()
{
     
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, HIGH);  // motor 1 terminal A = HIGH
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);   // motor 1 terminal B = LOW  -> forward

    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, HIGH);  // motor 2 terminal A = HIGH
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);   // motor 2 terminal B = LOW  -> forward
}

/*
 * Both motors spin backward at the given speed
 */
void DCMOTOR_voidRevers()
{
    

    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, LOW);   // motor 1 terminal A = LOW
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, HIGH);  // motor 1 terminal B = HIGH -> reversed

    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, LOW);   // motor 2 terminal A = LOW
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, HIGH);  // motor 2 terminal B = HIGH -> reversed
}

/*
 * Pivot right: motor 1 spins forward, motor 2 stays stopped
 */
void DCMOTOR_voidRight()
{
     

    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, HIGH);  // motor 1 -> forward
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);

    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, LOW);   // motor 2 -> stopped
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
}

/*
 * Pivot left: motor 2 spins forward, motor 1 stays stopped
 */
void DCMOTOR_voidLeft()
{
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, LOW);   // motor 1 -> stopped
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);

    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, HIGH);  // motor 2 -> forward
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
}

/*
 * Both motors stopped
 */
void DCMOTOR_voidStop()
{ 

    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, LOW);
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);

    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, LOW);
    DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
}