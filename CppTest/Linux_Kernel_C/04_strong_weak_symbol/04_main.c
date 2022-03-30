#include <stdio.h>

int 	__attribute__ ((weak)) a = 4;
short 	__attribute__ ((weak)) b = 4;

// void __attribute__((weak)) func(void)
// {
// 	printf("%s %s: a = %d\n", __FILE__, __FUNCTION__, a);
// 	printf("%s %s: b = %d\n", __FILE__, __FUNCTION__, b);
// }
void func();

int main()
{
	printf("%s %s: a = %d\n", __FILE__, __FUNCTION__, a);
	printf("%s %s: b = %d\n", __FILE__, __FUNCTION__, b);
	func();
	return 0;
}
