export ROOTDIR := $(shell pwd)
export CC := arm-none-eabi-gcc
export RM := rm -rf
export MKDIR := mkdir -p

export BUILDDIR := $(ROOTDIR)/Build

ifeq ($(MAKECMDGOALS),)
	MACHINE = Stellaris
else
	MACHINE = $(MAKECMDGOALS)
endif
export MACHINE

SUBDIR := Source \
		Drivers \


TARGET := firmware

all: $(TARGET) 

$(TARGET): $(BUILDDIR) $(SUBDIR)
	$(CC) -o $@ -mcpu=cortex-m3 -mthumb -T Source/GCC/gcc_arm_$(MACHINE).ld --specs=nosys.specs $(wildcard $(BUILDDIR)/HAL/$(MACHINE)/*.o) $(wildcard $(BUILDDIR)/Source/*.o)

$(BUILDDIR):
	@$(MKDIR) $@

$(SUBDIR):
	@$(MAKE) -C $@

run:
	qemu-system-arm -M lm3s811evb -cpu cortex-m3 -kernel $(TARGET) -display none -serial stdio

debug:
	qemu-system-arm -M lm3s811evb -cpu cortex-m3 -kernel $(TARGET) -d in_asm,cpu,unimp -display none -semihosting

gdb:
	qemu-system-arm -M lm3s811evb -cpu cortex-m3 -kernel $(TARGET) -d in_asm,cpu,unimp -display none -semihosting -S -s

clean:
	$(RM) $(BUILDDIR) $(TARGET)

.PHONY: all $(SUBDIR)