//关系运算符重载

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	bool operator==(Person & p)
	{
		// if(this == &p)
		// {
		// 	cout << "不要与自己进行对比" << endl;
		// 	return false;
		// }
		return !(m_Age != p.m_Age || m_Name != m_Name);
	}

	bool operator!=(Person & p)
	{
		return (m_Age != p.m_Age || m_Name != m_Name);
	}

	string m_Name;
	int m_Age;
};

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-20 20:39:16
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	int a = 2, b = 2;
	if(a == b)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}

	Person p1("xiaobai", 18);
	Person p2("xiaobai", 12);

	if(p1 == p2)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}

	if(p1 == p1)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
	return 0;
}
