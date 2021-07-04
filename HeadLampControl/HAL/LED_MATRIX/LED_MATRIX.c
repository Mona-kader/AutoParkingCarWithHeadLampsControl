#include"../MCAL/SPI/SPI.h"
#include <util/delay.h>
#include"../LIB/memmap128.h"
#include"LED_MATRIX.h"
SPI_config_t SPI_CONFIGURATION={MASTER,MSB,PRE_8,IE_SPI_D};
void max7221_int(void)
{
	 SPI_init(SPI_CONFIGURATION);

		max7221_send(0x0c,0x00);          //     Shutdown
		max7221_send(0x09,0x00);          //   No decode for digits 7–0
		max7221_send(0x0A,0x07);          //   Intensity Register Format at 8/16
		max7221_send(0x0b,0x07);          //    Display digits 0 1 2 3
		max7221_send(0x0c,0x01);          // Normal Operation
	}

void max7221_send (char cmd ,char data)
	{
	//ENABLE SLAVE
		DIO_void_Set_Pin_Value(PORTB_ID,PIN0,LOW);
		SPDR=cmd;
		while((SPSR&(1<<SPIF))==0);
	    SPDR=data;
	    while((SPSR&(1<<SPIF))==0);

	//disable SLAVE
	DIO_void_Set_Pin_Value(PORTB_ID,PIN0,HIGH);


	}
void Upper_Leds(void)
{
    	max7221_send(DIG0,255);
		max7221_send(DIG1,255);
		max7221_send(DIG6,0);
		max7221_send(DIG7,0);

}
void Lower_Leds(void)
{
	    max7221_send(DIG0,0);
		max7221_send(DIG1,0);
		max7221_send(DIG6,255);
		max7221_send(DIG7,255);

}

void ALL_Leds_ON(void)
{
	max7221_send(DIG0,255);
	max7221_send(DIG1,255);
	max7221_send(DIG2,255);
	max7221_send(DIG3,255);
	max7221_send(DIG4,255);
	max7221_send(DIG5,255);
    max7221_send(DIG6,255);
	max7221_send(DIG7,255);
}
void ALL_Leds_OFF(void)
{
	max7221_send(DIG0,0);
	max7221_send(DIG1,0);
	max7221_send(DIG2,0);
	max7221_send(DIG3,0);
	max7221_send(DIG4,0);
	max7221_send(DIG5,0);
    max7221_send(DIG6,0);
	max7221_send(DIG7,0);
}
