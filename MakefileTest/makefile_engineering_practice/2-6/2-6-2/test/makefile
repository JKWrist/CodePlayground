.PHONY:clean
hello:main.o
	make -C ../dll
	gcc -o hello main.o -L../dll -ldll
main.o:main.c
	gcc -o $@ -c $^

clean:
	rm -f main.o hello
	cd ../dll && make clean

