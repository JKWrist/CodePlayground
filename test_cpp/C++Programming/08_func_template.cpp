#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

void mySwapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void mySwapDouble(double &a, double &b)
{
	double temp = a;
	a = b;
	b = temp;
}

//利用函数模板实现通用交换函数
template<typename T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

//模板不能单独使用，必须指定T 才可以使用
template<typename T>
void mySwap2()
{

}

void test01()
{
	int a = 10;
	int b = 20;
	cout << a << endl;
	cout << b << endl;

	mySwapInt(a, b);
	cout << a << endl;
	cout << b << endl;

	mySwap(a, b);
	cout << a << endl;
	cout << b << endl;

	char e = 'c';
	//1、自动类型推导，必须导出一致的T数据类型，才可以正常的使用模板
	//推导不出一致的T，因此无法调用
	//mySwap(a, e);

	//2、显示指定类型
	mySwap<int>(a, b);

	mySwap2<int>();//candidate template ignored: couldn't infer template argument 'T'

	double c = 3.14;
	double d = 1.1;
	mySwap(c, d);
	cout << c << endl;
	cout << d << endl;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-06 08:46:01
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
