
//hena shanehtag array zay elly fat

#include"SPI.h"
#include"stdlib.h"
void(*ptfunc_SPI)(void);
void SPI_init(SPI_config_t config)
{
	//BEHES YKON GDID EL CONTROL REGISTER
	SPCR=0X00;
//ENABLE SPI
	SPCR|=(1<<SPE);
//if master

#if SPI_MODE==SPI_MASTER
//	DATA ORDER
	SPCR|=(config.Boreder<<DORD);
	//SET MODE
	SPCR|=(config.mode<<MSTR);

	//FIRST MASK&PRESCALLER
	SPCR|=(config.prescaler&0x03);
	SPCR|=(config.prescaler>>2);

	//MOSI
	DIO_void_Set_Pin_Dirction(PORTB_ID,PIN2,OUTPUT);
	//MISO
	DIO_void_Set_Pin_Dirction(PORTB_ID,PIN3,INPUT);
	//CLCK
	DIO_void_Set_Pin_Dirction(PORTB_ID,PIN1,OUTPUT);
	//SS
	DIO_void_Set_Pin_Dirction(PORTB_ID,PIN0,OUTPUT);

#elif SPI_MODE==SPI_SLAVE
		//MOSI
		DIO_void_Set_Pin_Dirction(PORTB_ID,PIN2,INPUT);
		//MISO
		DIO_void_Set_Pin_Dirction(PORTB_ID,PIN3,OUTPUT);
		//CLCK
		DIO_void_Set_Pin_Dirction(PORTB_ID,PIN1,INPUT);
		//SS
		DIO_void_Set_Pin_Dirction(PORTB_ID,PIN0,INPUT);
#endif
	//ENABLE INTERRUPT
		SPCR|=(config.SPIEN<<SPIE);





}
void SPI_send_byte(SPI_config_t config,uint8 data)
{
	//ENABLE SLAVE
	DIO_void_Set_Pin_Value(PORTB_ID,PIN0,LOW);
SPDR=data;
if(config.SPIEN)
{

}
else
{
	while((SPSR&(1<<SPIF))==0);
}
//disable SLAVE
DIO_void_Set_Pin_Value(PORTB_ID,PIN0,HIGH);
}
uint8 SPI_recv_byte(SPI_config_t config)
{

	if(config.SPIEN)
	{

	}
	else{
	while((SPSR&(1<<SPIF))==0);
	}
	return SPDR;
}


void SPI_send_bytes(SPI_config_t config,uint8 *data,uint8 buf)
{

	//ENABLE SLAVE
	DIO_void_Set_Pin_Value(PORTB_ID,PIN0,LOW);


if(config.SPIEN)
{
	SPDR=*data;
}
else
{

while(buf)
{

	SPDR=*data;
	while((SPSR&(1<<SPIF))==0);
data++;
--buf;
}

}
//disable SLAVE
DIO_void_Set_Pin_Value(PORTB_ID,PIN0,HIGH);
}


uint8 *SPI_recv_bytes(SPI_config_t config,uint8 buf)
{

	uint8 *ptr=(uint8*)malloc(buf*sizeof(uint8));
	uint8 i=0;
	if(config.SPIEN)
	{
		ptr[i]=SPDR;
	}
	else{

		while(buf)
		{
	while((SPSR&(1<<SPIF))==0);
	ptr[i]=SPDR;
	i++;
	--buf;
		}
	}
	return ptr;
}
