.PHONY:all clean

all: server.out 

server.out:mult_thread.c
	gcc mult_thread.c -o server.out -lpthread

clean:
	rm *.out