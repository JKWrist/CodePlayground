ifeq ("$(DEBUG)","true")
CC = gcc -g
else
CC = gcc
endif

.PHONY:clean hello

all:hello

hello:hello.o player.c
	echo $(CC)
	$(CC) -o hello lcd.o player.o
	
clean:
	rm *.o hello
