#include"../HAL/ULTRASONIC/ULTRASONIC.h"
#include"../HAL/LCD_V2/LCD_V2.h"
#include"../HAL/LED_MATRIX/LED_MATRIX.h"
volatile uint32 front_wheel=0,back_wheel=0;
volatile uint8 fla1=0,fla2=0;
void project_init(void);
void LED_CODE(void);
void LED_CODE2(void);
int main()
{
project_init();
while(1)
{

if((DIO_value_type_Get_Pin_Value(PORTD_ID,PIN0)==0)||(fla1==1))
{
	 LED_CODE2();
fla1=1;
if(DIO_value_type_Get_Pin_Value(PORTD_ID,PIN0)==0)
		{
	    fla1=0;
	LED_CODE();
		}
}


}

	return 0;
}

void project_init(void)
{
	//ON THE LEDS
	DIO_void_Set_Pin_Dirction(PORTD_ID,PIN0,INPUT);
	DIO_void_Set_Pin_Value(PORTD_ID,PIN0,HIGH);
	LCD_vidDirections();
		LCD_vidInit();
		Ultrasonic_init();
		sei();
		max7221_int();
		ALL_Leds_OFF();
}

void LED_CODE(void)
{
	 ALL_Leds_OFF();
	LCD_vidGotoxy(0,0);
    LCD_vidWriteString("F_W");
	front_wheel=Ultrasonic_front_Get_Distance();
	LCD_vidGotoxy(4,0);
	LCD_vidWriteString("   ");
	LCD_vidGotoxy(4,0);
	LCD_vidWriteUnSignedInteger(front_wheel);

	LCD_vidGotoxy(8,0);
	LCD_vidWriteString("B_W");
    back_wheel=Ultrasonic_back_Get_Distance();
    LCD_vidGotoxy(12,0);
    LCD_vidWriteString("   ");
	LCD_vidGotoxy(12,0);
	LCD_vidWriteUnSignedInteger(back_wheel);

	if((front_wheel>back_wheel)&&((front_wheel-back_wheel)>5))
	{
		//tale3a matab
		LCD_vidGotoxy(0,1);
		LCD_vidWriteString("NAZEL MATAB");

	}
	else if((front_wheel<back_wheel)&&((back_wheel-front_wheel)>5))
		{
		LCD_vidGotoxy(0,1);
		LCD_vidWriteString("TALE3A MATAB");

		}
	else
			{
			LCD_vidGotoxy(0,1);
			LCD_vidWriteString("STRAAAAAAAAAAIT");

			}
}

void LED_CODE2(void)
{

	LCD_vidGotoxy(0,0);
    LCD_vidWriteString("F_W");
	front_wheel=Ultrasonic_front_Get_Distance();
	LCD_vidGotoxy(4,0);
	LCD_vidWriteString("   ");
	LCD_vidGotoxy(4,0);
	LCD_vidWriteUnSignedInteger(front_wheel);

	LCD_vidGotoxy(8,0);
	LCD_vidWriteString("B_W");
    back_wheel=Ultrasonic_back_Get_Distance();
    LCD_vidGotoxy(12,0);
    LCD_vidWriteString("   ");
	LCD_vidGotoxy(12,0);
	LCD_vidWriteUnSignedInteger(back_wheel);

	if((front_wheel>back_wheel)&&((front_wheel-back_wheel)>5))
	{
		//tale3a matab
		LCD_vidGotoxy(0,1);
		LCD_vidWriteString("NAZEL MATAB");
		ALL_Leds_OFF();
		Upper_Leds();

	}
	else if((front_wheel<back_wheel)&&((back_wheel-front_wheel)>5))
		{
		LCD_vidGotoxy(0,1);
		LCD_vidWriteString("TALE3A MATAB");
		ALL_Leds_OFF();
		Lower_Leds();
		}
	else
	{
			LCD_vidGotoxy(0,1);
			LCD_vidWriteString("STRAAAAAAAAAAIT");
			ALL_Leds_ON();

			}
}
