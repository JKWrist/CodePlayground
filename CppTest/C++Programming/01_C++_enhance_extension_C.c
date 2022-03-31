// gcc -v
// Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
// Apple clang version 12.0.0 (clang-1200.0.32.27)
// Target: x86_64-apple-darwin20.1.0
// Thread model: posix
// InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin

//C++ 对 C 语言的增强 与 扩展

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a;
int a = 10;

//2、函数检测增强 返回值没有检测 形参类型没有检测 函数调用参数个数没有检测
//warning: type specifier missing, defaults to 'int'
getRectS(w, h)
{
	return w * h;
}

void test01()
{
	printf("%d\n", getRectS(10, 10, 10));  //too many arguments in call to 'getRectS
}

//3、类型转换检测增强
void test02()
{
	char * p = malloc(64);
}

//4、struct 增强
struct Person
{
	int age;
	//void func(); //error: field 'func' declared as a function
	//C 语言下结构体不可以有函数
};

void test03()
{
	struct Person p; //创建结构体变量时候，必须加关键字 struct
	p.age = 100;
}

//5、bool类型扩展 C语言下 没有这个类型
//bool a;   // error: unknown type name 'bool'

//6、三目运算符增强
void test04()
{
	//?:

	int a = 10;
	int b = 20;

	printf("ret = %d\n", a > b ? a : b);
	*(a > b? &a: &b) = 100;

	printf("%d\n", a);
	printf("%d\n", b);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-03-31 19:48:44
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	test01();

	test02();

	test03();

	test04();
	
	return 0;
}
