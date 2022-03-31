//C++ 对 C 语言的增强 与 扩展

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//1、全局变量检测增强
int a;

//int a = 10;
//error: redefinition of 'a'

//2、函数检测增强，返回值检测，形参类型检测，函数调用参数个数
int getRectS(int w,int h)
{
	return w * h;
}

void test01()
{
	printf("%d\n", getRectS(10, 10));
}

//3、类型转换检测增强
void test02()
{
	//error: cannot initialize a variable of type 'char *' with an
    //  rvalue of type 'void *
	char * p = (char *) malloc(64);
}

//4、struct 增强 C++可以放函数，创建结构体变量，可以简化关键字 struct
struct Person
{
	int age;
	void func()
	{
		age++;
	}
};

void test03()
{
	Person p;
	p.age = 17;
	p.func();
	cout << "p 的 age = " << p.age << endl;
}

//5、bool类型扩展 C语言下 没有这个类型  C++ 有 bool类型
bool flag = true; //bool 类型 代表 真和假       true ---> 真(1) false ----> 假(0)

//6、三目运算符增强
void test04()
{
	//?:
	int a = 10;
	int b = 20;
	printf("ret = %d\n", a > b ? a : b);

	(a < b ? a : b) = 100;  //C++下返回的是变量 b = 100
	printf("%d\n", a);
	printf("%d\n", b);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-03-31 19:47:27
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
