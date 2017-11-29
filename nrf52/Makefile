# Project name
BIN = nrf52

# Include paths (nRF5 SDK)
SDK_DIR = nRF5_SDK_12.3.0_d7731ad

INC = -I$(SDK_DIR)/components/toolchain/cmsis/include \
      -I$(SDK_DIR)/components/toolchain/gcc \
      -I$(SDK_DIR)/components/toolchain \
      -I$(SDK_DIR)/components/device \
      -I$(SDK_DIR)/components/drivers_nrf/common \
      -I$(SDK_DIR)/components/drivers_nrf/hal \
      -I$(SDK_DIR)/components/drivers_nrf/nrf_soc_nosd \
      -I$(SDK_DIR)/components/libraries/util

INC += -L$(SDK_DIR)/components/toolchain/gcc

# ASM and C (e.g. startup) source files and linker script outside src directory
SRC_ASM = $(SDK_DIR)/components/toolchain/gcc/gcc_startup_nrf52.S
SRC_C = $(SDK_DIR)/components/toolchain/system_nrf52.c
SRC_LD = $(SDK_DIR)/examples/peripheral/blinky/pca10040/blank/armgcc/blinky_gcc_nrf52.ld

# Defines required by included libraries
DEF = -DNRF52 \
      -DNRF52832 \
      -DCONFIG_GPIO_AS_PINRESET

# CPU architecture
ARCHFLAGS = -mcpu=cortex-m4
FPFLAGS = -mfloat-abi=hard -mfpu=fpv4-sp-d16

include ../cm-makefile/common.mk
include jlink.mk

# Disable GCC warnings which are triggered by the nRF5 SDK
WARNFLAGS += -Wno-pedantic -Wno-undef -Wno-sign-conversion -Wno-unused-parameter
