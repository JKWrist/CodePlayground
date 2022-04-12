//this 指针的应用
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
		//用途1、解决名称冲突
		this->age = age;
		//age = age;
	}

	//this指针，隐式加载每个成员函数中
	bool compareAge(Person &p)
	{
		if(this->age == p.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Person personAddPerson(Person &p)
	{
		this->age += p.age;
		return *this; //*this就是本体
	}

	int age;
};

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-12 09:05:50
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	//this指针，指向 被调用的成员函数，所属的对象
	Person p1(10);
	cout << "p1 的年龄为" << p1.age << endl;

	Person p2(10);
	bool ret = p1.compareAge(p2);
	if(ret)
	{
		cout << "p1与p2相等" << endl;
	}

	p1.personAddPerson(p2).personAddPerson(p2);
	cout << "p1 的年龄为" << p1.age << endl;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-12 09:05:50
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
