.PHONY:all clean


all: client.out server.out

client.out:client.c
	gcc client.c -o client.out

server.out:server.c
	gcc server.c -o server.out

clean:
	rm *.out