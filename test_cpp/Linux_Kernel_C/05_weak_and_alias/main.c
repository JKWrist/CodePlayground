#include <stdio.h>
//void __attribute__((weak)) f(void);

void f(void)
{
	printf("%s\n", __FUNCTION__);
}

int main(void)
{
	f();
	return 0;
}
