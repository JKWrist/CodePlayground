#include <stdio.h>

void __attribute__((weak)) func(void);
int a;

int main()
{
	printf("main: a = %d\n", a);
	if(func)
	{
		func();
	}

	return 0;
}