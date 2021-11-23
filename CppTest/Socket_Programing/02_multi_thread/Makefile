.PHONY:all clean

all: mult_thread_server.out 

mult_thread_server.out:mult_thread.c
	gcc mult_thread.c wrap.c -o server.out

clean:
	rm *.out