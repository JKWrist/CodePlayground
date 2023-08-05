//类模板中成员函数的创建时机

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person show 调用" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{

	}
};

//类模板中的成员函数，并不是一开始创建的，而是在运行阶段确定出T的数据类型才去创建
template<class T>
class MyClass
{
public:
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
	T obj;
};

void test01()
{
	MyClass <Person1> p1;
	p1.func1();

	MyClass <Person2> p2;
	p2.func2();
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-07 17:58:27
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	test01();
	return 0;
}
