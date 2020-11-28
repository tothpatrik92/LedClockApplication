################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/app.c \
../src/main.c 

OBJS += \
./src/app.o \
./src/main.o 

C_DEPS += \
./src/app.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/app.o: ../src/app.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/CMSIS/Include" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\illum" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\src" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\button" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\led" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\system" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\event" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/EFR32MG12_BRD4166A/config" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"src/app.d" -MT"src/app.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32MG12P332F1024GL125=1' -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/CMSIS/Include" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\illum" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\src" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\button" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\led" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\system" -I"C:\Users\patrik\SimplicityStudio\v5_workspace\LedClockApplication\event" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.0//hardware/kit/EFR32MG12_BRD4166A/config" -O0 -Wall -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"src/main.d" -MT"src/main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


