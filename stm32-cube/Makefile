# Project name
BIN = stm32-cube

# Include paths (STM32CubeF0 SDK)
CUBE_DIR = ../thirdparty/STM32CubeF0
CUBE_DEVICE_DIR = $(CUBE_DIR)/Drivers/CMSIS/Device/ST/STM32F0xx
CUBE_HAL_DIR = $(CUBE_DIR)/Drivers/STM32F0xx_HAL_Driver

INC = -I$(CUBE_DIR)/Drivers/CMSIS/Include \
      -I$(CUBE_DEVICE_DIR)/Include \
      -I$(CUBE_HAL_DIR)/Inc

# ASM and C (e.g. startup) source files and linker script outside src directory
SRC_ASM = $(CUBE_DEVICE_DIR)/Source/Templates/gcc/startup_stm32f030x8.s
SRC_C = $(CUBE_DEVICE_DIR)/Source/Templates/system_stm32f0xx.c \
        $(CUBE_HAL_DIR)/Src/stm32f0xx_hal.c \
        $(CUBE_HAL_DIR)/Src/stm32f0xx_hal_cortex.c \
        $(CUBE_HAL_DIR)/Src/stm32f0xx_hal_rcc.c \
        $(CUBE_HAL_DIR)/Src/stm32f0xx_hal_rcc_ex.c \
        $(CUBE_HAL_DIR)/Src/stm32f0xx_hal_gpio.c

SRC_LD = $(CUBE_DIR)/Projects/STM32F030R8-Nucleo/Templates/SW4STM32/STM32F030R8-Nucleo/STM32F030R8Tx_FLASH.ld

# Defines required by included libraries
DEF := -DSTM32F030x8
DEF += -DUSE_HAL_DRIVER

# OpenOCD setup
OPENOCD ?= openocd -f board/st_nucleo_f0.cfg

include ../cm-makefile/config.mk
include ../cm-makefile/openocd.mk
include ../cm-makefile/rules.mk

# Disable GCC warnings which are triggered by the STM32CubeF0 SDK
WARNFLAGS += -Wno-undef -Wno-conversion -Wno-unused

# OpenOCD-specific target
.PHONY: erase
erase:
	$(CMD_ECHO) $(OPENOCD) -c \
	"init; \
	reset halt; \
	sleep 100; \
	stm32f1x mass_erase 0; \
	shutdown"
