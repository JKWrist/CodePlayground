.PHONY:clean

hello:main.o
	make -C ../static
	gcc -o $@ $^ -L../static -lmath
main.o:main.c
	gcc -o $@ -c $^

clean:
	-rm hello main.o
	-cd ../static && make clean

