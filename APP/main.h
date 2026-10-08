/*
 * main.h
 */ 
#ifndef MAIN_H_
#define MAIN_H_

#define  F_CPU 16000000UL 
#include <util/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h" 
#include "../LIB/InterruptVectorNum.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../HAL/DCMOTOR/DCMOTOR_interface.h"
#include "../MCAL/TIM1/TIMER1_interface.h"
#include "../HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "../HAL/ServoMotor/SERVO_interface.h"

#endif /* MAIN_H_ */