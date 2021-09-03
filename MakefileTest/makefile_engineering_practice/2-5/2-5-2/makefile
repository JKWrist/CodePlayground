.PHONY:all
LIB = /home/hello/libhello.a
LIB1 = $(dir $(LIB))
LIB2 = $(notdir $(LIB))
LIB3 = $(suffix	$(LIB))
LIB4 = $(basename $(LIB))
LIB5 = $(addsuffic .c,$(LIB4))
LIB6 = $(addprefix /usr/lib/,$(LIB2))

SRC = $(wildcard *.c)

all:
	@echo $(LIB1)
	@echo $(LIB2)
	@echo $(LIB3)
	@echo $(LIB4)
	@echo $(LIB5)
	@echo $(LIB6)
	@echo $(SRC)

