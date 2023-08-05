#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//1、函数模板与普通函数的区别以及调用规则
template <class T>
T myAdd(T a, T b)
{
	return a + b;
}

int myAdd2(int a, int b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	//如果使用自动类型推到，是不可以发生隐式类型转换的
	//myAdd(a, c);

	myAdd2(a, c);
}

//2、函数模板和普通函数的调用规则
template<class T>
void myPrint(T a, T b)
{
	cout << "函数模板调用" << endl;
}


//函数模板通过具体类型产生不同的函数  --- 通过函数模板产生的函数  称为 模板函数
void myPrint(int a ,int b)
{
cout << "myPrint(int a ,int b) 调用" << endl;
}

void myPrint(double a ,double b)
{
cout << "myPrint(double a ,double b) 调用" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "函数模板(T a, T b, T c) 调用" << endl;
}


void test02()
{
	//1、如果函数模板和普通函数都可以调用，那么悠闲调用普通函数
	int a = 10, b = 20;
	myPrint(a, b);

	//2、如果想强调用函数模板，可以使用空模板参数列表
	myPrint<>(a, b);

	//3、函数模板也可以发生函数重载
	myPrint(a, b, 10);

	//4、如果函数模板能产生更好的匹配，那么悠闲使用函数模板
	char c = 'c';
	char d = 'd';
	myPrint(c, d);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-07 16:00:46
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	test01();

	test02();

	return 0;
}
