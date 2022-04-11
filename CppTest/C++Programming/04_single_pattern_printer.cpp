
//单例模式，打印机案例

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Printer
{
public:
	static Printer * getInstance()
	{
		return m_printer;
	}

	void printText(string text)
	{
		m_Count++;
		cout << "打印 : " << text << endl;
		cout << "打印机使用次数 : " << m_Count << endl;
	}
	int m_Count;
private:
	Printer() 
	{
		m_Count = 0;
		cout << "打印机构造调用" << endl;
	};
	Printer(const Printer & p){};
	static Printer * m_printer;
};

//Printer * Printer::m_printer = new Printer();
Printer * Printer::m_printer = new Printer;

void test01()
{
	Printer * p1 = Printer::getInstance();
	p1->printText("入职证明");
	p1->printText("离职证明");
	p1->printText("加薪申请");
	p1->printText("旅游申请");
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-11 21:38:56
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
