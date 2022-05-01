//继承方式

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//公共继承
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 : public Base
{
public:
	void func()
	{
		m_A = 100; //父类中 公共权限 子类中变为 公共权限
		m_B = 100; //父类中 保护权限 子类中变为 保护权限
		//m_C = 100; //父类中私有成员 子类无法访问
	}
};

class Son2 : protected Base
{
public:
	void func()
	{
		m_A = 100; //父类中 公共权限 子类中变为 保护权限
		m_B = 100; //父类中 保护权限 子类中变为 保护权限
		//m_C = 100; //父类中私有成员 子类无法访问
	}
};

class Son3 : private Base
{
public:
	void func()
	{
		m_A = 100; //父类中 公共权限 子类中变为 私有权限
		m_B = 100; //父类中 保护权限 子类中变为 私有权限
		//m_C = 100; //父类中私有成员 子类无法访问
	}
};

void test01()
{
	Son1 son1;
	son1.m_A = 100;
	//son1.m_B = 100; // 'm_B' is a protected member of 'Base'

	Son2 son2;
	//son2.m_A = 100; //'m_A' is a protected member of 'Base'

	Son3 son3;
}


/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-01 20:05:26
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
