################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.c 

S_UPPER_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0/platform/Device/SiliconLabs/EFR32MG12P/Source/GCC/startup_efr32mg12p.S 

OBJS += \
./CMSIS/EFR32MG12P/startup_efr32mg12p.o \
./CMSIS/EFR32MG12P/system_efr32mg12p.o 

C_DEPS += \
./CMSIS/EFR32MG12P/system_efr32mg12p.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFR32MG12P/startup_efr32mg12p.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0/platform/Device/SiliconLabs/EFR32MG12P/Source/GCC/startup_efr32mg12p.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/CMSIS/Include" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\illum" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\src" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\button" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\system" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\event" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\led" -I"C:/Users/patrik/SimplicityStudio/v5_workspace/LedClockApplication/event" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/EFR32MG12_BRD4166A/config" '-DEFR32MG12P332F1024GL125=1' -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -x assembler-with-cpp -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/EFR32MG12P/system_efr32mg12p.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0/platform/Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/CMSIS/Include" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\illum" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\src" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\button" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\led" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\system" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\event" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/EFR32MG12_BRD4166A/config" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"CMSIS/EFR32MG12P/system_efr32mg12p.d" -MT"CMSIS/EFR32MG12P/system_efr32mg12p.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


