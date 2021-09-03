.PHONY:clean

CC = gcc
BIN = hello
OBJS = player.o lcd.o

$(BIN): $(OBJS)
	cd / && pwd
	$(CC) -o $(BIN) $(OBJS)

player.o:player.c
	$(CC) -o player.o  -c player.c

lcd.o:lcd.c
	$(CC) -o lcd.o  -c lcd.c

clean:
	-rm $(BIN) $(OBJS)
