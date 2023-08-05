//类模板

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

template<class NAMETYPE, class AGETYPE = int> // 类模板中可以有默认参数
class Person
{
public:
	Person(NAMETYPE name, AGETYPE age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名： " << m_Name << " 年龄 " << m_Age << endl;
	}

	NAMETYPE m_Name;
	AGETYPE m_Age;
};

void test01()
{
	//类模板和函数模板区别
	//1、类模板不可以使用自动类型推导，只能用显示指定类型
	//2、类模板中，可以有默认参数
	//Person p1("孙悟空", 10);
	Person <string> p1("孙悟空", 100);
	p1.showPerson();
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-07 17:40:28
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
