#include <stdio.h>

int a = 1;
int b;

//a 强符号，b 弱符号
void func(void)
{
	printf("%s %s : a = %d\n", __FILE__, __FUNCTION__, a);
	printf("%s %s : b = %d\n", __FILE__, __FUNCTION__, b);
}