//函数的默认参数与占位参数

#include <iostream>
using namespace std;

//默认参数 语法
	//形参 ：类型 变量 = 默认值

//注意事项,如果有一个位置有了默认参数，那么从这个位置起，从左到有必须有默认值
int func(int a, int b, int c = 10)
{
	return a + b + c;
}

void test01()
{
	cout << func(20, 10) << endl;
}

//函数的声明和实现 只能有一个提供默认参数，不可以同时加默认参数
void myFunc(int a = 10, int b = 10);
void myFunc(int a, int b)
//void myFunc(int a = 20, int b = 10)
{

}

//占位参数 只写一个类型进行占位，调用是必须要传入占位值
//暂时没有用到
void func2(int a, int = 1)
{

}

void test02()
{
	func2(10);
}

int main()
{
	test01();
	test02();

	return 0;
}