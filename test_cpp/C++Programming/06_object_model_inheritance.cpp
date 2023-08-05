//继承中的对象模型
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //父类中私有属性，子类中访问不到，是由编译器隐藏了
};

class Son : public Base
{
public:
	int m_D;
};

void test01()
{
	// 4 8 12 16
	cout << "size of son " << sizeof(Son) << endl;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-01 21:13:46
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
