//继承中的同名静态成员处理
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Base
{
public:
	static void func()
	{
		cout << "Base中的func调用 " << endl;
	}

	static void func(int a)
	{
		cout << "Base中的func(int a)调用 " << endl;
	}

	static int m_A;
};

int Base::m_A = 10;

class Son : public Base
{
public:
	static void func()
	{
		cout << "Son 中的 func 调用" << endl;
	}
	static int m_A;
};

int Son::m_A = 20;

void test01()
{
	//1、通过对象访问
	Son s;
	cout << "m_A" << s.m_A << endl;
	cout << "Base 中的m_A " << s.Base::m_A << endl;

	//2、通过类名访问
	cout << "m_A = " << Son::m_A << endl;

	//3、通过类名的反事实 访问 父类中的m_A静态成员变量
	cout << "Base中的m_A" << Son::Base::m_A << endl;
}

void test02()
{
	//1、通过对象
	Son s;
	s.func();
	s.Base::func();

	//2、通过类名
	Son::func();

	//当子类重定义父类中的同名成员函数，子类中的成员商户说会隐藏掉父类中的所有版本，需要加作用域调用
		
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-02 14:56:43
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
