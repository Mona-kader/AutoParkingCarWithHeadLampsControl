################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER/TIMER_1/Timer1.c 

OBJS += \
./MCAL/TIMER/TIMER_1/Timer1.o 

C_DEPS += \
./MCAL/TIMER/TIMER_1/Timer1.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER/TIMER_1/%.o: ../MCAL/TIMER/TIMER_1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\AVR_WorkSpce\yaaaa5\HAL" -I"E:\AVR_WorkSpce\yaaaa5\LIB" -I"E:\AVR_WorkSpce\yaaaa5\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


