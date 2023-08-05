#include <stdio.h>

int a;
int b = 2;
void func();

//a 弱符号，b 强符号
int main()
{
	printf("%s %s : a = %d\n", __FILE__, __FUNCTION__, a);
	printf("%s %s : b = %d\n", __FILE__, __FUNCTION__, b);

	func();
	return 0;
}