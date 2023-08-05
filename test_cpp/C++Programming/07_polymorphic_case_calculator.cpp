//多态案例计算器
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class calculator
{
public:
	int getResult(string op)
	{
		if(op == "+")
		{
			return m_A + m_B;
		}
		else if(op == "-")
		{
			return m_A - m_B;
		}
		else if(op == "*")
		{
			return m_A * m_B;
		}
		else if(op == "/")
		{
			return m_A / m_B;
		}
	}

	int m_A;
	int m_B;
};

//设计远侧，开闭原则
//对扩展进行开放，对修改进行关闭

//利用多态实现计算器
class AbstractCalculator
{
public:
	//纯虚函数
	//如果一个类中包含了纯虚函数，那么这个各类就无法实例化对象了，这个类通常我们称为 抽象类
	//抽象类的子类 必须重写，父类中的纯虚函数，否则也属于抽象类
	virtual int getResult() = 0;
	
	int m_A;
	int m_B;
};

//加法计算器
class AddCalculator : public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A + m_B;
	}
};

//减法计算器
class SubCalculator : public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A - m_B;
	}
};

//乘法计算器
class MulCalculator : public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A * m_B;
	}
};

//除法计算器
class DivCalculator : public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A / m_B;
	}
};

class Test : public AbstractCalculator
{
	int getResult()
	{
		return 0;
	}
};

void test01()
{
	calculator c;
	c.m_A = 10;
	c.m_B = 20;
	cout << c.getResult("+") << endl;

	AbstractCalculator * cal1 = new AddCalculator;
	cal1->m_A = 1;
	cal1->m_B = 2;
	cout << cal1->getResult() << endl;
	delete cal1;

	AbstractCalculator * cal2 = new MulCalculator;
	cal2->m_A = 5;
	cal2->m_B = 3;
	cout << cal2->getResult() << endl;
	delete cal2;	
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-04 17:01:37
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
