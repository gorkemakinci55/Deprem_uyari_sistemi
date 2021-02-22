################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BMA_400/bma400.c \
../Core/Src/BMA_400/bma400_work_functions.c \
../Core/Src/BMA_400/interrupt_bma400.c \
../Core/Src/BMA_400/spi_bma_interface.c 

OBJS += \
./Core/Src/BMA_400/bma400.o \
./Core/Src/BMA_400/bma400_work_functions.o \
./Core/Src/BMA_400/interrupt_bma400.o \
./Core/Src/BMA_400/spi_bma_interface.o 

C_DEPS += \
./Core/Src/BMA_400/bma400.d \
./Core/Src/BMA_400/bma400_work_functions.d \
./Core/Src/BMA_400/interrupt_bma400.d \
./Core/Src/BMA_400/spi_bma_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/BMA_400/bma400.o: ../Core/Src/BMA_400/bma400.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L071xx -c -I../bma_400_files -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../examples -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/BMA_400/bma400.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/BMA_400/bma400_work_functions.o: ../Core/Src/BMA_400/bma400_work_functions.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L071xx -c -I../bma_400_files -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../examples -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/BMA_400/bma400_work_functions.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/BMA_400/interrupt_bma400.o: ../Core/Src/BMA_400/interrupt_bma400.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L071xx -c -I../bma_400_files -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../examples -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/BMA_400/interrupt_bma400.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/BMA_400/spi_bma_interface.o: ../Core/Src/BMA_400/spi_bma_interface.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L071xx -c -I../bma_400_files -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../examples -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/BMA_400/spi_bma_interface.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

