################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include serial/subdir.mk
-include led/subdir.mk
-include illum/subdir.mk
-include event/subdir.mk
-include emlib/subdir.mk
-include button/subdir.mk
-include CMSIS/EFR32MG12P/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LedClockApplication.axf

# Tool invocations
LedClockApplication.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "LedClockApplication.ld" -Xlinker --gc-sections -Xlinker -Map="LedClockApplication.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o LedClockApplication.axf "./CMSIS/EFR32MG12P/startup_efr32mg12p.o" "./CMSIS/EFR32MG12P/system_efr32mg12p.o" "./button/button_control.o" "./button/button_handler.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_rtcc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./event/event_control.o" "./event/event_handler.o" "./illum/illum_control.o" "./illum/illum_handler.o" "./led/led_control.o" "./led/led_handler.o" "./serial/retargetio.o" "./serial/retargetserial.o" "./src/app.o" "./src/main.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: LedClockApplication.hex'
	arm-none-eabi-objcopy -O ihex "LedClockApplication.axf" "LedClockApplication.hex"
	@echo ' '

	@echo 'Building bin file: LedClockApplication.bin'
	arm-none-eabi-objcopy -O binary "LedClockApplication.axf" "LedClockApplication.bin"
	@echo ' '

	@echo 'Building s37 file: LedClockApplication.s37'
	arm-none-eabi-objcopy -O srec "LedClockApplication.axf" "LedClockApplication.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "LedClockApplication.axf" -A
	@echo ' '

	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) LedClockApplication.axf
	-@echo ' '

post-build:
	-cmd //c 'C:/Users/patrik/SimplicityStudio/v5_workspace/LedClockApplication\GNU ARM v7.2.1 - Debug\download.bat' LedClockApplication
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
