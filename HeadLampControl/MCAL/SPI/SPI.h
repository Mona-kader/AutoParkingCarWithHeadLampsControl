/*
 * SPI.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_
#include"../../LIB/std_types.h"
#include"../../LIB/utils.h"
#include"../../LIB/memmap128.h"
#include"../../MCAL/DIO/DIO.h"
#define SPI_MODE SPI_MASTER
#define  SPI_MASTER 1
#define  SPI_SLAVE  0
typedef enum
{
	PRE_4,
	PRE_16,
	PRE_64,
	PRE_128,

	PRE_2,
	PRE_8,
	PRE_32,
	PRE_D_64,
}SPI_PRE_t;


typedef enum
{
	SLAVE,
	MASTER
}SPI_MODE_t;

typedef enum
{
	MSB,
	LSB
}SPI_DORD_t;

typedef enum
{
	IE_SPI_D,
	IE_SPI_E
}SPI_SPIEN_t;


typedef struct
{

	SPI_MODE_t 	mode;
#if   SPI_MODE==SPI_MASTER
	SPI_DORD_t  Boreder;
	SPI_PRE_t   prescaler;
#endif
	SPI_SPIEN_t SPIEN;
	//CALL BACK FUNCTION
	//void(*ptfunc_SPI)(void);
}SPI_config_t;

void SPI_init(SPI_config_t config);
void SPI_send_byte(SPI_config_t config,uint8 data);
uint8 SPI_recv_byte(SPI_config_t config);

void SPI_send_bytes(SPI_config_t config,uint8 *data,uint8 buf);
uint8 *SPI_recv_bytes(SPI_config_t config,uint8 buf);
#endif /* MCAL_SPI_SPI_H_ */
