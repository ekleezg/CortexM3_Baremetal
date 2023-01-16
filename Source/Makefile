CFLAGS = -O0 -g -c -mcpu=cortex-m3 -mthumb -DARMCM3 -I$(ROOTDIR)/Include -I$(ROOTDIR)/Drivers/CMSIS/Include -I$(ROOTDIR)/Drivers/HAL
SRC_BUILDDIR := $(BUILDDIR)/Source

OBJS = main.o \
		startup_ARMCM3.o \
		system_ARMCM3.o \
		syscall.o \


all: $(SRC_BUILDDIR) $(OBJS)

$(SRC_BUILDDIR):
	@$(MKDIR) $@

%.o: %.c
	$(CC) $(CFLAGS) -o $(SRC_BUILDDIR)/$@ $<