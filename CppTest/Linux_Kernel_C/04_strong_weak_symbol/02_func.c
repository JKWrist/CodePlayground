#include <stdio.h>

int a __attribute__((weak)) = 1;

void func()
{
	printf("%s %s : a = %d\n", __FILE__, __FUNCTION__, a);
}