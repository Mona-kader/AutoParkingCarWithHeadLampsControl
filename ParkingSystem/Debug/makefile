################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UARTT/subdir.mk
-include MCAL/TIMER/TIMER_3/subdir.mk
-include MCAL/TIMER/TIMER_1/subdir.mk
-include MCAL/TIMER/TIMER_0/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/ULTRASONIC/subdir.mk
-include HAL/MAGNET_DOOR/subdir.mk
-include HAL/LCD_V2/subdir.mk
-include HAL/BUZZER/subdir.mk
-include HAL/APP_SERV/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
CHALLENGE_17.lss \

FLASH_IMAGE += \
CHALLENGE_17.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: CHALLENGE_17.elf secondary-outputs

# Tool invocations
CHALLENGE_17.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CHALLENGE_17.map -mmcu=atmega128 -o "CHALLENGE_17.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CHALLENGE_17.lss: CHALLENGE_17.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CHALLENGE_17.elf  >"CHALLENGE_17.lss"
	@echo 'Finished building: $@'
	@echo ' '

CHALLENGE_17.hex: CHALLENGE_17.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CHALLENGE_17.elf  "CHALLENGE_17.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CHALLENGE_17.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 CHALLENGE_17.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: CHALLENGE_17.elf
	@echo 'Invoking: AVRDude'
	E:\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm128 -cusbasp -Uflash:w:CHALLENGE_17.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CHALLENGE_17.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
