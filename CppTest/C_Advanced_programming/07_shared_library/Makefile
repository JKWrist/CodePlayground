./PHONTY:all

all:
	gcc -fpic -c fun1.c fun2.c
	gcc -shared fun1.o fun2.o -o libtest.so
	gcc main.c sum.c -I ./ -L ./ -ltest