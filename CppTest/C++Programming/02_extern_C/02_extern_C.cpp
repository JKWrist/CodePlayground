//extern C 浅析

#include <iostream>
#include "test.h"

extern "C" void show();

using namespace std;

void test01()  //objdump -D  a.out 可以看到此函数实际变成了 __Z6test01v
{
	//实际上变成了 __Z4showv,C++中函数重载会修饰函数名，但是shwo是c文件链接时会失败
	//mac 中 clang 编译器中，即使不加 extern "C" 也可以正常运行

	show();
}

int main()
{
	test01();
	return 0;
}