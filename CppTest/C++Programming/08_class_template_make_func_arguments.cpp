//类模板做函数参数
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

template <class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名 " << this->m_Name << " 年龄 " << this->m_Age << endl;;
	}

	T1 m_Name;
	T2 m_Age;
};

//1、指定传入类型
void doWork(Person <string, int>&p)
{
	p.showPerson();
}

void test01()
{
	Person <string, int> p("孙悟空", 100);
	doWork(p);
}

//2、函数模板参数化
template <class T1, class T2>
void doWork2(Person <T1, T2> &p)
{
	cout << "T1数据类型" << sizeof(T1) << endl;
	cout << "T2数据类型" << sizeof(T2) << endl;
}

void test02()
{
	Person <string, int> p("孙悟空", 999);
	doWork2(p);
}

//3、整个类 模板化
template<class T>
void doWork3(T &p)
{
	cout << "T数据类型" << sizeof(T) << endl;
}

void test03()
{
	Person <string, int> p("孙悟空", 999);
	doWork3(p);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-08 14:14:23
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	//test01();
	//test02();

	test03();

	return 0;
}
