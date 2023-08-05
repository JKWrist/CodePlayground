//类模板的继承问题

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

template<class T>
class Base
{
public:
	T m_A;
};

//必须指定出父类中的T数据类型，才能给子类分配内存
class Son : public Base <int>
{

};


template<class T>
class Base2
{
public:
	T m_A;
};

template<class T1, class T2>
class Son2 : public Base2 <T2>
{
public:
	Son2()
	{
		cout << sizeof(T1) << endl;
		cout << sizeof(T2) << endl;
	}
	T1 m_B;
};

void test01()
{
	Son2 <int, double> s;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-08 14:47:40
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
