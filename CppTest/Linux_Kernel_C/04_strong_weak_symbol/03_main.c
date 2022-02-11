#include <stdio.h>

int a = 4;

void func(void)
{
	printf("I am a strong symbol\n");
}

int main()
{
	func();
	printf("%s %s : a = %d\n", __FILE__, __FUNCTION__, a);
}