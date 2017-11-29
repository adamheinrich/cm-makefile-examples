# Setup linker script generator and add the script to outputs (so it can be
# automatically removed by `make clean`):

DEVICE = $(OPENCM3_DEVICE)

-include $(OPENCM3_DIR)/mk/genlink-config.mk

LDSCRIPT = $(SRC_LD)
Q ?= $(CMD_ECHO)
OUTPUTS += $(LDSCRIPT)

-include $(OPENCM3_DIR)/mk/genlink-rules.mk
