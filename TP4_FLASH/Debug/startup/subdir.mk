################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f303xc.s 

OBJS += \
./startup/startup_stm32f303xc.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo %cd%
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -I"C:/Users/simu34/workspace/stm32f3discovery_hal_lib" -I"C:/Users/simu34/TP4_FLASH_V2/inc" -I"C:/Users/simu34/workspace/stm32f3discovery_hal_lib/CMSIS/core" -I"C:/Users/simu34/workspace/stm32f3discovery_hal_lib/CMSIS/device" -I"C:/Users/simu34/workspace/stm32f3discovery_hal_lib/HAL_Driver/Inc/Legacy" -I"C:/Users/simu34/workspace/stm32f3discovery_hal_lib/HAL_Driver/Inc" -I"C:/Users/simu34/workspace/stm32f3discovery_hal_lib/Utilities/Components/Common" -I"C:/Users/simu34/workspace/stm32f3discovery_hal_lib/Utilities/Components/l3gd20" -I"C:/Users/simu34/workspace/stm32f3discovery_hal_lib/Utilities/Components/lsm303dlhc" -I"C:/Users/simu34/workspace/stm32f3discovery_hal_lib/Utilities/STM32F3-Discovery" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


