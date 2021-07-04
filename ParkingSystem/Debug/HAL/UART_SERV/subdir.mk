################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/UART_SERV/UART_SERV.c 

OBJS += \
./HAL/UART_SERV/UART_SERV.o 

C_DEPS += \
./HAL/UART_SERV/UART_SERV.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/UART_SERV/%.o: ../HAL/UART_SERV/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\AVR_WorkSpce\CHALLENGE_7\HAL\APP_SERV" -I"E:\AVR_WorkSpce\CHALLENGE_7\HAL\LCD_V2" -I"E:\AVR_WorkSpce\CHALLENGE_7\HAL\UART_SERV" -I"E:\AVR_WorkSpce\CHALLENGE_7\HAL\ULTRASONIC" -I"E:\AVR_WorkSpce\CHALLENGE_7\LIB" -I"E:\AVR_WorkSpce\CHALLENGE_7\MCAL\DIO" -I"E:\AVR_WorkSpce\CHALLENGE_7\MCAL\TIMER" -I"E:\AVR_WorkSpce\CHALLENGE_7\MCAL\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


