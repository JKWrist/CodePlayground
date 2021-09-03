.PHONY:clean

N=1
OBJS = lcd.o player.o
BIN = mp3

target:$(OBJS)
	@echo "target N= $(N)"
	gcc -o $(BIN)  $(OBJS)

%.o:N=3

lcd.o:
	@echo "lcd.o N= $(N)"
	gcc -o lcd.o -c lcd.c

player.o:
	@echo "player.o N= $(N)"
	gcc -o player.o -c player.c

clean:
	@echo "clean N= $(N)"
	-rm $(OBJS) $(BIN)
