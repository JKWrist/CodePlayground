#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char i = 255;
	printf("%d %x\n", i, i);
	char a = ~i;
	printf("%d %x\n", a, a);
	return 0;
}
