//类模板碰到友元函数

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person <T1, T2> &p);

template<class T1, class T2>
void printPerson3(Person <T1, T2> &p)
{
	cout << "姓名: " << p.m_Name << " 年龄: " << p.m_Age << endl;
}

template <class T1, class T2>
class Person
{
public:
// 	//1、友元函数类内实现
// 	friend void printPerson(Person <T1, T2> &p)
// 	{
// 		cout << "姓名: " << p.m_Name << " 年龄: " << p.m_Age << endl;
// 	}

	//2、友元函数 类外实现
	friend void printPerson2(Person<T1, T2> &p);

	friend void printPerson3(Person<T1, T2> &p);
private:
	string m_Name;
	int m_Age;
};

template<class T1, class T2>
void printPerson2(Person <T1, T2> &p)
{
	cout << "姓名: " << p.m_Name << " 年龄: " << p.m_Age << endl;
}

void test01()
{

	Person <string, int> p("Tom", 100);
	//printPerson(p);
	//printPerson2(p);
	printPerson3(p);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-09 08:47:46
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
