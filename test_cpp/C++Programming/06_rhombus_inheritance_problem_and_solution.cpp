//菱形继承问题以及解决

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//动物类
class Animal
{
public:
	int m_Age; //年龄
};

//Animal称为 虚基类

//羊类
class Sheep : virtual public Animal
{

};

//驼类
class Tuo : virtual public Animal
{

};

//羊驼
class SheepTuo : public Sheep,public Tuo
{

};

void test01()
{
	SheepTuo st;

	cout << "sizeof(st) " << sizeof(st) << endl;
	st.Sheep::m_Age = 20;
	st.Tuo::m_Age = 5;
	

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "age " << st.m_Age << endl;

	//当发生虚继承后，sheep和tuo类中 继承了一个 vbptr的 虚基类指针 指向的是一个虚基类表 vbtable
	//虚基类表中记录了 偏移量，通过偏移量 可以找到唯一的一个 m_Age
}

void test02()
{
	SheepTuo st;
	st.m_Age = 10;
	
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-04 14:07:45
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
