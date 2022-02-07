#include <stdio.h>

int a = 4;
void __attribute__((weak)) func(void);

int main()
{
	printf("%s %s: a = %d\n", __FILE__, __FUNCTION__, a);
	func();
	return 0;
}
