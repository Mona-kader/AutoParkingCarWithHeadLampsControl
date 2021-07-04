################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_V2/LCD_V2.c 

OBJS += \
./HAL/LCD_V2/LCD_V2.o 

C_DEPS += \
./HAL/LCD_V2/LCD_V2.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_V2/%.o: ../HAL/LCD_V2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\AVR_WorkSpce\CHALLENGE_17\HAL\APP_SERV" -I"E:\AVR_WorkSpce\CHALLENGE_17\HAL\LCD_V2" -I"E:\AVR_WorkSpce\CHALLENGE_17\HAL\ULTRASONIC" -I"E:\AVR_WorkSpce\CHALLENGE_17\LIB" -I"E:\AVR_WorkSpce\CHALLENGE_17\MCAL\DIO" -I"E:\AVR_WorkSpce\CHALLENGE_17\MCAL\TIMER" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


