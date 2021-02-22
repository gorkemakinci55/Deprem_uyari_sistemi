################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BC_95/at_commands_functions.c \
../Core/Src/BC_95/bc.95.c \
../Core/Src/BC_95/bc95_work_functions.c 

OBJS += \
./Core/Src/BC_95/at_commands_functions.o \
./Core/Src/BC_95/bc.95.o \
./Core/Src/BC_95/bc95_work_functions.o 

C_DEPS += \
./Core/Src/BC_95/at_commands_functions.d \
./Core/Src/BC_95/bc.95.d \
./Core/Src/BC_95/bc95_work_functions.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/BC_95/at_commands_functions.o: ../Core/Src/BC_95/at_commands_functions.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L071xx -c -I../bma_400_files -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../examples -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/BC_95/at_commands_functions.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/BC_95/bc.95.o: ../Core/Src/BC_95/bc.95.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L071xx -c -I../bma_400_files -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../examples -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/BC_95/bc.95.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/BC_95/bc95_work_functions.o: ../Core/Src/BC_95/bc95_work_functions.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L071xx -c -I../bma_400_files -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../examples -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/BC_95/bc95_work_functions.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

