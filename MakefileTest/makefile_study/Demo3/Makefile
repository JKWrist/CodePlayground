#include ./math/Makefile
VPATH=./math

main:MathFunctions main.cc
	gcc ./math/MathFunctions.o main.cc -o main

MathFunctions:
	cd math;pwd;make

.PHONY:clean
clean:
	rm main;cd math;make clean

