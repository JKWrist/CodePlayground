#include <iostream>
using namespace std;
void func(int a, int b = 10, int c = 36);
int main()
{
	func(99);
	return 0;
}

void func(int a, int b = 10, int c = 36)
{
	cout<<a<<", "<<b<<", "<<c<<endl;
}

//这段代码在编译时会报错，错误信息表明不能在函数定义和函数声明中同时指定默认参数