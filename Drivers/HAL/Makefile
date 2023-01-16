CFLAGS := -O0 -g -c -mcpu=cortex-m3 -mthumb -DARMCM3 -I$(ROOTDIR)/Include -I$(ROOTDIR)/Drivers/CMSIS/Include/ -I$(ROOTDIR)/Drivers/HAL/
HAL_BUILDDIR := $(BUILDDIR)/HAL/$(MACHINE)

OBJS = uart.o \


all: $(HAL_BUILDDIR) $(OBJS)

$(HAL_BUILDDIR):
	@$(MKDIR) $@

%.o: $(MACHINE)/%.c
	$(CC) $(CFLAGS) -o $(HAL_BUILDDIR)/hal_$@ $<