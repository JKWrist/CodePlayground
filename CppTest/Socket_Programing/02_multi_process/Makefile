.PHONY:all clean

all: mult_process_server.out 

mult_process_server.out:mult_process.c
	gcc mult_process.c wrap.c -o mult_process_server.out

clean:
	rm *.out