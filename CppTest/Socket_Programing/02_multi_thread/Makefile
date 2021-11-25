.PHONY:all clean

all: mult_thread_server.out 

mult_thread_server.out:mult_thread.c
	gcc mult_thread.c -o server.out -lphread

clean:
	rm *.out