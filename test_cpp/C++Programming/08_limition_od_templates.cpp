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
		m_Age = age;
		m_Name = name;
	}
	string m_Name;
	int m_Age;
};

//显示两个变量 对比 函数
template <class T>
bool myCompare(T &a, T &b)
{
	if(a == b)
	{
		return true;
	}
	return false;
}

//利用集体化技术，实现自定义数据类型，提供特殊模板
template<> bool myCompare(Person &a, Person &b)
{
	if(a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}
	return false;
}

void test01()
{
	int a = 10;
	int b = 10;

	bool ret = myCompare(a, b);
	if(ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}

	Person p1("aaa", 6);
	Person p2("aaa", 8);

	ret = myCompare(p1, p2);
	if(ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-07 17:23:44
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
