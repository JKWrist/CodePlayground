//继承中的构造和析构

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Base1
{
public:
	Base1()
	{
		cout << "Base1的构造函数调用" << endl; 
	}

	~Base1()
	{
		cout << "Base1的析构函数调用" << endl;
	}
};

class Other
{
public:
	Other()
	{
		cout << "Other 的构造函数调用" << endl;
	}
	~Other()
	{
		cout << "Other 的析构函数调用" << endl;
	}
};

class Son1 : public Base1
{
public:
	Son1()
	{
		cout << "Son1的构造函数调用" << endl;
	}

	~Son1()
	{
		cout << "Son1的析构函数调用" << endl;
	}
	Other Other;
};

void test01()
{
	Son1 son;  //先调用父类构造，再调用其他成员构造，再调用自身构造，析构的顺序与构造相反
}

class Base2
{
public:
	Base2(int a)
	{
		this->m_A = a;
		cout << "Base2 的构造函数调用" << endl;
	}
	int m_A;
};

class Son2 : public Base2
{
public:
	Son2(int a = 1000) : Base2(a) //利用初始化列表检查语法 显示调用父类中的其他构造函数
	{
		cout << "Son2的构造函数调用" << endl;
	}
};

//父类中 构造、析构、拷贝构造、operator= 是不会被子类继承下去的
void test02()
{
	Son2 s;
	cout << s.m_A << endl;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-01 21:23:42
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	//test01();

	test02();
	return 0;
}
