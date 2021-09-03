.PHONY:all clean

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
BIN = mp3

all: $(BIN) $(DEPS)
	@echo "0000 $(DEPS)"
ifneq ("$(DEPS)", "")
include $(DEPS)
endif
$(BIN):$(OBJS)
	gcc -o $@ $^
%.o:%.c
	@echo "1111 $(filter %.c,$^)"
	gcc -o $@ -c $(filter %.c,$^)
%.d:%.c
	gcc -MM $^ > $@

clean:
	rm -f $(BIN) $(OBJS) $(DEPS)

