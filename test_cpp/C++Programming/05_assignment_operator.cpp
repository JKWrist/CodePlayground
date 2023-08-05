//赋值运算符
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//编译器 默认给一个类4个函数 默认构造，析构，拷贝（值拷贝），operator=（值拷贝）
class Person
{
public:
	Person(char *name, int age)
	{
		cout << "有参构造" << endl;
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
		this->m_Age = age;
	}

	//重载 =
	Person & operator=(const Person &p)
	{
		cout << "重载 =, 赋值构造函数" << endl;
		//先释放原有堆区内容
		if(m_Name)
		{
			delete[] m_Name;
			m_Name = NULL;
		}
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
		return *this;
	}

	//拷贝构造
	Person(const Person & p)
	{
		cout << "拷贝构造" << endl;
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
	}

	//析构函数
	~Person()
	{
		cout << "析构函数" << endl;
		if(m_Name)
		{
			delete[] m_Name;
			m_Name = NULL;
		}
	}

	char *m_Name;
	int m_Age;
};

void test01()
{
	Person p1("Tom", 10);
	Person p2("Jerry", 20);
	p2 = p1;

	Person p3 = Person("", 0);
	p3 = p2 = p1;

	Person p4 = p3;
	cout << "p1姓名: " << p1.m_Name << "  p1年龄: " << p1.m_Age << endl;
	cout << "p2姓名: " << p2.m_Name << "  p2年龄: " << p2.m_Age << endl;
	cout << "p3姓名: " << p3.m_Name << "  p3年龄: " << p3.m_Age << endl;
	cout << "p4姓名: " << p4.m_Name << "  p4年龄: " << p4.m_Age << endl;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-20 20:00:58
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
