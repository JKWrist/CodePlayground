.PHONY:all

all:
	gcc -c fun1.c fun2.c
	ar rcs libfun.a fun1.o fun2.o
	gcc main.c sum.c -I./ -L./ -lfun