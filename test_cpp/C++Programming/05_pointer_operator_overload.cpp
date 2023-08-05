#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Person
{
public:
	Person(int age)
	{
		cout << "Person 的有参构造函数调用" << endl;
		this->m_Age = age;
	}

	void showAge()
	{
		cout << "年龄为: " << this->m_Age << endl;
	}

	~Person()
	{
		cout << "Person的析构调用" << endl;
	}

	int m_Age;
};

class SmartPointer
{
public:
	SmartPointer(Person * pPerson)
	{
		m_Person = pPerson;
	}

	//重载->运算符
	Person * operator->()
	{
		return this->m_Person;
	}
	//重载 * 运算符
	Person& operator*()
	{
		return *m_Person;
	}
	~SmartPointer()
	{
		if(this->m_Person != NULL)
		{
			delete m_Person;
			this->m_Person = NULL;
		}
	}
private:
	Person * m_Person;
};


void test01()
{
	// Person * p = new Person(18);
	// (*p).showAge();
	// p->showAge();
	// delete p;
	
	SmartPointer sp(new Person(18));
	sp->showAge();
	(*sp).showAge();
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-19 20:56:39
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
