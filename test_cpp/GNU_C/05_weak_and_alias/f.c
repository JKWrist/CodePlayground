#include <stdio.h>

void __f(void)
{
	printf("%s\n", __FUNCTION__);
}

void f() __attribute__ ((weak, alias("__f")));