.PHONY:clean
target = a.out
src = $(wildcard ./*.c)
objects = $(patsubst %.c, %.o, $(src))
CC = gcc

$(target):$(objects)
#	echo $(src)
#	echo $(objects)
	$(CC) -o $(target) $(objects)

clean:
	rm *.o