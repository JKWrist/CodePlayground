.PHONY:all

all:
	make -C lcd
	make -C usb
	make -C media
	make -C app

clean:
	find -name *.d|xargs rm
	find -name *.o|xargs rm
	rm app/mp3
