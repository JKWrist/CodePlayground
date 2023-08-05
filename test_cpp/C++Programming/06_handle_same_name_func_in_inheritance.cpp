//继承中的同名函数处理

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Base
{
public:
	Base()
	{
		this->m_A = 10;
	}

	void func()
	{
		cout << "Base中的func调用" << endl;
	}

	void func(int as)
	{
		cout << "Base中的func(int)调用" << endl;
	}
	int m_A;
};

class Son : public Base
{
public:
	Son()
	{
		this->m_A = 20;
	}

	void func()
	{
		cout << "Son中的func调用" << endl;
	}
	int m_A;
};

void test01()
{
	Son s1;
	cout << "s1.m_A = " << s1.m_A << endl;

	//我们可以利用作用域访问父类中的同名成员
	cout << "Base中的m_A = " << s1.Base::m_A << endl;
}

void test02()
{
	Son s1;
	s1.func();
	s1.Base::func();
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-01 22:01:19
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
