.PHONY:all clean

ifeq ("$(DEBUG)", "true")
CC = gcc -g
else
CC = gcc
endif

all:test1
all:test2
all:test3
	@echo "all"

test1 test3:
	@echo "Just for test1: $@"

test2:
	@echo "Just for test2"

hello:lcd.o player.o
	@echo "start build hello"
	$(CC) -o hello lcd.o player.o
	@echo "build hello success"

clean:
	-rm lcd.o hello player.o
