//重载加号运算符

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Person
{
public:
	Person(){};
	Person(int a, int b):m_A(a), m_B(b)
	{};

	//利用成员函数实现加号运算符重载
	Person operator+(Person &p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	int m_A;
	int m_B;
};

//利用全局函数实现加号运算符重载
/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-14 21:08:26
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	Person p1(10, 20);
	Person p2(20, 30);
	Person p3 = p1 + p1;
	//Person p3 = p1.operator+(p2); //成员函数的本质
	cout << "p3.m_A = " << p3.m_A << " p3.m_B = " << p3.m_B << endl;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-14 21:08:26
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
