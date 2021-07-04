################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/TIMER_3/subdir.mk
-include MCAL/TIMER/TIMER_1/subdir.mk
-include MCAL/TIMER/TIMER_0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/ULTRASONIC/subdir.mk
-include HAL/LED_MATRIX/subdir.mk
-include HAL/LCD_V2/subdir.mk
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
yaaaa5.lss \

FLASH_IMAGE += \
yaaaa5.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: yaaaa5.elf secondary-outputs

# Tool invocations
yaaaa5.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,yaaaa5.map -mmcu=atmega128 -o "yaaaa5.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

yaaaa5.lss: yaaaa5.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S yaaaa5.elf  >"yaaaa5.lss"
	@echo 'Finished building: $@'
	@echo ' '

yaaaa5.hex: yaaaa5.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex yaaaa5.elf  "yaaaa5.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: yaaaa5.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 yaaaa5.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: yaaaa5.elf
	@echo 'Invoking: AVRDude'
	E:\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm128 -Uflash:w:yaaaa5.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) yaaaa5.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
