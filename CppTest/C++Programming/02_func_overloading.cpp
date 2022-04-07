//函数重载

#include <iostream>
using namespace std;

//函数重载条件
//1、在同一个作用域
//2、函数名称相同
//3、参数个数、类型顺序不同

class Person
{
public:
	void func() //成员函数而不是全局函数
	{

	}
};

void func()
{
	cout << "func() 调用" << endl;
}

void func(int a)
{
	cout << "func(int a) 调用" << endl;
}

void func(double a)
{
	cout << "func(double a) 调用" << endl;
}

void func(int a, double b)
{
	cout << "func(int a, double b) 调用" << endl;
}

void func(double b, int a)
{
	cout << "func(double b, int a) 调用" << endl;
}

//返回值可不可以作为函数重载的条件? 不可以
//functions that differ only in their return type cannot be overloaded

// int func(double b, int a)
// {
// 	cout << "func(double b, int a) 调用" << endl;
// }

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-07 18:57:55
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	func();
	func(1);
	func(1.5);
	func(1, 1.5);
	func(1.5, 1);
}

//函数重载中引用的两个版本
// void func2(int a)
// {
// 	cout << "func2(int a) 调用" << endl;
// }

void func2(int &a)
{
	cout << "func2(int &a) 调用" << endl;
}

void func2(const int &a)
{
	cout << "func2(const int &a) 调用" << endl;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-07 19:04:49
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
	int a = 10;
	func2(a);   //避免二义性出现
}

//函数重载碰到默认参数，注意避免二义性出现
void func3(int a, int b = 10)
{
	cout << "func3(int a, int b = 10)  调用" << endl;
}

// void func3(int a)
// {
// 	cout << "func3(int a, int b = 10)  调用" << endl;
// }

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-07 19:15:11
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test03()
{
	func3(10);
}

int main()
{
	test01();
	test02();
	test03();
	return 0;
}