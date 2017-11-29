OPENCM3_FLAGS  = V=$(V)
OPENCM3_FLAGS += PREFIX=$(subst --,,$(CROSS_COMPILE)-)
OPENCM3_FLAGS += FP_FLAGS=$(FPFLAGS)
OPENCM3_FLAGS += DEBUG_FLAGS=$(DBGFLAGS)

HELP_TEXT += \n\
  libopencm3 - Build the libopencm3 library\n\
  libopencm3_clean - Remove files built in the libopencm3 folder

$(OPENCM3_DIR)/Makefile:
	$(error Error: libopencm3 is not available. Run \
		`git submodule update --init $(OPENCM3_DIR)` to initialize it)

$(OPENCM3_DIR)/lib/$(OPENCM3_LIB): $(OPENCM3_DIR)/Makefile
	$(CMD_ECHO) $(MAKE) -C $(OPENCM3_DIR) $(OPENCM3_FLAGS)

.PHONY: libopencm3
libopencm3: $(OPENCM3_DIR)/lib/$(OPENCM3_LIB)

.PHONY: libopencm3_clean
libopencm3_clean:
	$(CMD_ECHO) $(MAKE) -C $(OPENCM3_DIR) clean
