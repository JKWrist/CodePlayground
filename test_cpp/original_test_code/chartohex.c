#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int d1 = 0xd0;
	int d2 = 0xc;
	enum Delimiter
	{
		Delimiter_1 = 0xd0,
		Delimiter_2 = 0xc
	};
	printf("%x, %x\n", d1, d2);
	printf("%d, %d \n", Delimiter_1, Delimiter_2);
}