# Project name
BIN = stm32-cube-nohal

# Include paths (STM32CubeF0 SDK)
CUBE_DIR = ../thirdparty/STM32CubeF0
CUBE_DEVICE_DIR = $(CUBE_DIR)/Drivers/CMSIS/Device/ST/STM32F0xx

INC = -I$(CUBE_DIR)/Drivers/CMSIS/Include \
      -I$(CUBE_DEVICE_DIR)/Include

# ASM and C (e.g. startup) source files and linker script outside src directory
SRC_ASM = $(CUBE_DEVICE_DIR)/Source/Templates/gcc/startup_stm32f030x8.s
SRC_C = $(CUBE_DEVICE_DIR)/Source/Templates/system_stm32f0xx.c
SRC_LD = $(CUBE_DIR)/Projects/STM32F030R8-Nucleo/Templates/SW4STM32/STM32F030R8-Nucleo/STM32F030R8Tx_FLASH.ld

# Defines required by included libraries
DEF = -DSTM32F030x8

# OpenOCD setup
OPENOCD ?= openocd -f board/st_nucleo_f0.cfg

include ../cm-makefile/config.mk
include ../cm-makefile/openocd.mk
include ../cm-makefile/rules.mk

# Disable GCC warnings which are triggered by the STM32CubeF0 SDK
WARNFLAGS += -Wno-undef -Wno-conversion

# OpenOCD-specific target
.PHONY: erase
erase:
	$(CMD_ECHO) $(OPENOCD) -c \
	"init; \
	reset halt; \
	sleep 100; \
	stm32f1x mass_erase 0; \
	shutdown"
