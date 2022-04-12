//常函数与常对象

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//const char *p 
//char const *p
//char * const p
using namespace std;

class Person
{
public:
	Person(int age)
	{
		this->m_Age = age;
	}
	
	//常函数：修饰成员中的this指针，让指针指向的值不可以修改
	void showPerson() const
	{
		m_A = 100;
		//this指针的本质: const Person * const this
		//this = NULL; //指针的指向不可以修改，而指针指向的值 可以改
		cout << "Person age = " << this->m_Age << endl;
	}
	
	void func()
	{
		m_Age = 100;
		cout << "func 调用" << endl; 
	}
	int m_Age;
	mutable int m_A; //常函数 或者 常对象、有些特殊属性依然想修改，加入关键字mutable
};
/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-12 20:55:01
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	//常对象
	const Person p1(10);

	//p1.m_Age = 10;   //2、不可以修改
	p1.showPerson();
	//p1.func();		//3、常对象，只能调用常函数
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-12 20:55:01
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
