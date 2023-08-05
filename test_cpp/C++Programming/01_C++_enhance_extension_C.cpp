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
	printf("-----------%d----------\n", 1);

	printf("%d\n", getRectS(10, 10));
}

//3、类型转换检测增强
void test02()
{
	printf("-----------%d----------\n", 2);
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
	printf("-----------%d----------\n", 3);
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
	printf("-----------%d----------\n", 4);
	//?:
	int a = 10;
	int b = 20;
	printf("ret = %d\n", a > b ? a : b);

	(a < b ? a : b) = 100;  //C++下返回的是变量 b = 100
	printf("%d\n", a);
	printf("%d\n", b);
}

//7、const增强
//全局const 与 C 语言中结论一致

const int m_A = 100;
void test05()
{
	printf("-----------%d----------\n", 5);
	//m_A = 200;

	// int * p = (int *)&m_A;
	// *p = 200;    //这种方式也不能修改

	//局部const
	const int m_B = 100;
	//m_B = 200;
	int * p2 = (int *)&m_B;         //这里赋值的时候给了一个临时的变量
	*p2 = 200;

	cout << "m_B = " << m_B << endl;  //所以没有修改原有const变量
	cout << "*p2 = " << *p2 << endl;
	
	//通过这个来开，目前 C++ 与 c 都可以使用一个常量来初始化一个数组
	int arr1[m_A];
	int arr2[m_B];
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
	test05();
	
	return 0;
}
