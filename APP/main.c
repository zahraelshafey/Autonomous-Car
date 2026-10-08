#include "main.h"

#define SAFE_DISTANCE       40
#define WARNING_DISTANCE    20

 
static u16 MeasureDistance(void)
{
	ULTRASONIC_voidTrigger();
	_delay_ms(60);

	if(ULTRASONIC_u8IsDistanceReady() == 1)
	{
		return ULTRASONIC_u16GetDistance();
	}

	return 0;
}

int main(void)
{
	LCD_voidInit();
	ULTRASONIC_voidInit();
	DCMOTOR_voidInit();
	SERVO_voidInit();

	GI_voidEnable();
	
		_delay_ms(1000);
		SERVO_voidSetAngle(-90);
		_delay_ms(1000);
		SERVO_voidSetAngle(90);
		_delay_ms(1000);
		SERVO_voidSetAngle(0);

	while(1)
	{
		u16 Loc_u16Distance = MeasureDistance();

		if(Loc_u16Distance != 0)
		{
			LCD_voidGotoXY(0,0);
			LCD_voidSendString((s8*)"Dist: ");
			LCD_voidSendNumber(Loc_u16Distance);
			LCD_voidSendString((s8*)" cm   ");

			LCD_voidGotoXY(0,1);

			if(Loc_u16Distance > SAFE_DISTANCE)
			{
				LCD_voidSendString((s8*)"SAFE        ");
				DCMOTOR_voidForward();
			}
			else if(Loc_u16Distance > WARNING_DISTANCE)
			{
				LCD_voidSendString((s8*)"WARNING     ");
				DCMOTOR_voidStop();
			}
			else
			{
				u16 Loc_u16Left;
				u16 Loc_u16Right;

				LCD_voidSendString((s8*)"DANGER SCAN ");
				DCMOTOR_voidStop();

				SERVO_voidSetAngle(-90);          // ???? ????
				_delay_ms(600);
				Loc_u16Left = MeasureDistance();

				SERVO_voidSetAngle(90);           // ???? ????
				_delay_ms(900);
				Loc_u16Right = MeasureDistance();

				SERVO_voidSetAngle(0);            // ????? ????
				_delay_ms(600);

				LCD_voidGotoXY(0,1);
				if(Loc_u16Left > Loc_u16Right)
				{
					LCD_voidSendString((s8*)"TURN LEFT    ");
					DCMOTOR_voidLeft();
				}
				else
				{
					LCD_voidSendString((s8*)"TURN RIGHT   ");
					DCMOTOR_voidRight();
				}

				_delay_ms(600);                   // ??? ??????
				DCMOTOR_voidStop();
			}
		}
	}
}