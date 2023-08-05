VPATH=./math
MAKE=make
main:main.cc subsystem
	gcc main.cc ./math/MathFunctions.o -o main

#main.o:main.cc ./math/MathFunctions.h
#	gcc main.cc ./math/MathFunctions.h -o main.o

.PHONY:subsystem clean

subsystem:
	$(MAKE) -C math

clean:
	rm main
