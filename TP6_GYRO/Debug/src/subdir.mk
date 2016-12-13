################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/selftest.c \
../src/stm32f3xx_it.c \
../src/syscalls.c \
../src/system_stm32f3xx.c \
../src/usbd_conf.c \
../src/usbd_core.c \
../src/usbd_ctlreq.c \
../src/usbd_desc.c \
../src/usbd_hid.c \
../src/usbd_ioreq.c 

OBJS += \
./src/main.o \
./src/selftest.o \
./src/stm32f3xx_it.o \
./src/syscalls.o \
./src/system_stm32f3xx.o \
./src/usbd_conf.o \
./src/usbd_core.o \
./src/usbd_ctlreq.o \
./src/usbd_desc.o \
./src/usbd_hid.o \
./src/usbd_ioreq.o 

C_DEPS += \
./src/main.d \
./src/selftest.d \
./src/stm32f3xx_it.d \
./src/syscalls.d \
./src/system_stm32f3xx.d \
./src/usbd_conf.d \
./src/usbd_core.d \
./src/usbd_ctlreq.d \
./src/usbd_desc.d \
./src/usbd_hid.d \
./src/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -DSTM32F30 -DSTM32F3DISCOVERY -DSTM32F3 -DSTM32F303VCTx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib" -I"C:/Users/simu29/workspace/TP6_GYRO/inc" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/CMSIS/core" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/CMSIS/device" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/HAL_Driver/Inc/Legacy" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/HAL_Driver/Inc" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/Utilities/Components/Common" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/Utilities/Components/l3gd20" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/Utilities/Components/lsm303dlhc" -I"C:/Users/simu29/workspace/stm32f3discovery_hal_lib/Utilities/STM32F3-Discovery" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


