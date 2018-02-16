DIRS := 1bitsy
DIRS += nrf51 nrf52
DIRS += stm32-cube stm32-cube-nohal
DIRS += stm32-libopencm3

.PHONY: all
all: $(DIRS:=.build)

.PHONY: clean
clean: $(DIRS:=.clean)

%.build:
	@echo "  BUILD   $*"
	@$(MAKE) -C $*  > /dev/null

%.clean:
	@echo "  CLEAN   $*"
	@$(MAKE) -C $* distclean > /dev/null
