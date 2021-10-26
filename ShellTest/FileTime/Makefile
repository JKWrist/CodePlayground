.PHONY:all

all:
	$(shell cat version | head -n 1| sed -r 's/.*202(.*)UTC.*/\1/' | sed 's/[ -:]//g')
	