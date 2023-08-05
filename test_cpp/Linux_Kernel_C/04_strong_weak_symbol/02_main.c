#include <stdio.h>

int a;
void func();

//a 弱符号，b 强符号
int main()
{
	printf("%s %s : a = %d\n", __FILE__, __FUNCTION__, a);
	func();
	return 0;
}