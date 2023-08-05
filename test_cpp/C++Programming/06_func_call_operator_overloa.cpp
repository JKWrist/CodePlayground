//函数调用运算符重载

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


class MyPrint
{
public:
	void operator()(string test)
	{
		cout << test <<  endl;
	}
};

void MyPrint2(string str)
{
	cout << str << endl;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-20 21:09:03
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	MyPrint myPrint;
	myPrint("123123");  //彷函数 本质是一个对象 函数对象

	MyPrint2("12312312321");
}

class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void test02()
{
	MyAdd myAdd;
	printf("%d\n", myAdd(1, 2));
}
/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-20 21:03:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	test01();
	test02();
	return 0;
}
