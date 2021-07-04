/*
 * LED_MATRIX.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef HAL_LED_MATRIX_LED_MATRIX_H_
#define HAL_LED_MATRIX_LED_MATRIX_H_
#include"../MCAL/SPI/SPI.h"
#define DIG0                    0b00000001
#define DIG1                    0b00000010
#define DIG2                    0b00000011
#define DIG3                    0b00000100
#define DIG4                    0b00000101
#define DIG5                    0b00000110
#define DIG6                    0b00000111
#define DIG7                    0b00001000

void max7221_send(char cmd ,char data);
void max7221_int(void);
void ALL_Leds_OFF(void);
void ALL_Leds_ON(void);
void Lower_Leds(void);
void Upper_Leds(void);
#endif /* HAL_LED_MATRIX_LED_MATRIX_H_ */
