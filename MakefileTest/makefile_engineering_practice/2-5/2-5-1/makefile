.PHONY:all

SRCS = player.c lcd.c  usb.c media.c hello.h main.txt  
OBJS = $(subst .c,.o,$(strip $(SRCS)))
#OBJS = $(subst .c,.o,$(SRCS))
DEPS = $(patsubst %.c,%.d,$(SRCS))
DEPS2 = $($(DEOS):.d,.e)
FIND = $(findstring usb,$(SRCS))
FILTER = $(filter %.c %.h, $(SRCS))


all:
	@echo "OBJS = $(OBJS)"
	@echo "DEPS = $(DEPS)"
	@echo "DEPS2 = $(DEPS2)"
	@echo "FIND = $(FIND)"
	@echo "FILTER = $(FILTER)"
