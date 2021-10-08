.PHONY:clean,all
src = $(wildcard *.c)
objects = $(patsubst %.c, %.o, $(src))

all:$(objects)
	echo $(src)
	echo $(objects)
	gcc $(objects)

#%.o:%.c

clean:
	rm -rf *.o