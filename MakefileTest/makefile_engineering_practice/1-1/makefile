target:hello
	
hello:helloworld.c
	gcc -E helloworld.c -o hello.i
	gcc -S hello.i -o hello.s
	$(AS) hello.s -o hello.o
	gcc -o hello hello.o

clean:
	-rm hello.*
	-rm hello
