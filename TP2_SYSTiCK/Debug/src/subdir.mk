################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm32f3xx_it.c \
../src/syscalls.c \
../src/system_stm32f3xx.c 

OBJS += \
./src/main.o \
./src/stm32f3xx_it.o \
./src/syscalls.o \
./src/system_stm32f3xx.o 

C_DEPS += \
./src/main.d \
./src/stm32f3xx_it.d \
./src/syscalls.d \
./src/system_stm32f3xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -DSTM32F30 -DSTM32F3DISCOVERY -DSTM32F3 -DSTM32F303VCTx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib" -I"C:/Users/simu29/workspace/TP2_SYSTiCK/inc" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/CMSIS/core" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/CMSIS/device" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/HAL_Driver/Inc/Legacy" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/HAL_Driver/Inc" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/Utilities/Components/Common" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/Utilities/Components/l3gd20" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/Utilities/Components/lsm303dlhc" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/Utilities/STM32F3-Discovery" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


