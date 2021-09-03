.PHONY:all clean

all:
	make -C lcd
	make -C usb
	make -C media
	make -C app

clean:
	rm -f mp3
	find *.o |xargs rm
	find *.d |xargs rm

