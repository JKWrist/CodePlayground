#include <stdio.h>

void __f(void)
{
	printf("%s %s\n", __FILE__, __FUNCTION__);
}

void f() __attribute__((alias("__f")));

int main()
{
	f();
	return 0;
}