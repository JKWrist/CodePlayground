#include <stdio.h>

int a __attribute__ ((weak)) = 1;

void __attribute__ ((weak)) func(void)
{
	printf("%s %s : a = %d\n", __FILE__, __FUNCTION__, a);
}