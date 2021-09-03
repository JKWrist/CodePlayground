.PHONY:clean
OBJS = player.o lcd.o
BIN = mp3

$(BIN):$(OBJS)
	@echo "BIN------$@:$^"
	gcc -o $@ $^

player.o:player.c
	@echo "player.o ------$@:$^"
	gcc -o $@ -c $^

lcd.o:lcd.c
	@echo "lcd.o  ------$@:$^"
	gcc -o $@ -c $^

clean:
	-rm $(BIN) $(OBJS)
