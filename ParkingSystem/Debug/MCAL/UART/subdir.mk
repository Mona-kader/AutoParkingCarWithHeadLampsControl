################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART/UART.c 

OBJS += \
./MCAL/UART/UART.o 

C_DEPS += \
./MCAL/UART/UART.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/%.o: ../MCAL/UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\AVR_WorkSpce\CHALLENGE_7\HAL\APP_SERV" -I"E:\AVR_WorkSpce\CHALLENGE_7\HAL\LCD_V2" -I"E:\AVR_WorkSpce\CHALLENGE_7\HAL\UART_SERV" -I"E:\AVR_WorkSpce\CHALLENGE_7\HAL\ULTRASONIC" -I"E:\AVR_WorkSpce\CHALLENGE_7\LIB" -I"E:\AVR_WorkSpce\CHALLENGE_7\MCAL\DIO" -I"E:\AVR_WorkSpce\CHALLENGE_7\MCAL\TIMER" -I"E:\AVR_WorkSpce\CHALLENGE_7\MCAL\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


