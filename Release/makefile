################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/BMA_400/subdir.mk
-include Core/Src/BC_95/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
deprem\ uyari.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
deprem\ uyari.list \

OBJCOPY_BIN += \
deprem\ uyari.bin \


# All Target
all: deprem\ uyari.elf secondary-outputs

# Tool invocations
deprem\ uyari.elf: $(OBJS) $(USER_OBJS) C:\Users\gorkem.akinci\STM32CubeIDE\workspace_1.3.0\deprem\ uyari\STM32L071RBTX_FLASH.ld
	arm-none-eabi-gcc -o "deprem uyari.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"C:\Users\gorkem.akinci\STM32CubeIDE\workspace_1.3.0\deprem uyari\STM32L071RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="deprem uyari.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

deprem\ uyari.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "deprem uyari.list"
	@echo 'Finished building: $@'
	@echo ' '

deprem\ uyari.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "deprem uyari.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
