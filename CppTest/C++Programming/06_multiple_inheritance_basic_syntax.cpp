//多继承的基本语法

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Base1
{
public:
	Base1()
	{
		this->m_A = 10;
	}

	int m_A;
};

class Base2
{
public:
	Base2()
	{
		this->m_A = 20;
	}
	int m_A;
};

//多继承
class Son : public Base1, public Base2
{
public:
	int m_C;
	int m_D;
};

void test01()
{
	cout << "sizeof son " << sizeof(Son) << endl;

	Son s;
	//当多继承的两个父类中有同名成员，需要加作用域区分
	cout << s.Base1::m_A << endl;
	cout << s.Base2::m_A << endl;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-04 13:12:26
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
