.PHONY:all clean

SRCS = $(wildcar *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

BIN := $(addprefix ~/test/xujunze/makefile_engineering_practice/3.4,$(BIN))
LINK_OBJ_DIR = ~/test/xujunze/makefile_engineering_practice/3.4/link_obj

$(shell mkdir -p $(LINK_OBJ_DIR))

OBJS := $(addprefix $(LINK_OBJ_DIR)/,$(OBJS))

LINK_OBJ = $(wildcard $(LINK_OBJ_DIR)/*.o)
LINK_OBJ +=$(OBJS)

all:$(DEPS) $(OBJS) $(BIN)
ifneq ("$(wildcard $(DEPS))", "")
include $(DEPS)
endif

$(BIN):$(LINK_OBJ)
	@echo "LINK_OBJ = $(LINK_OBJ)"
	gcc -o $@ $^

%.d:%.c
	gcc -MM S^ > $@
clean:
	find -name *.d|xargs rm
	rm -f $(BIN) $(OBJS)
