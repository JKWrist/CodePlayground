#include<iostream>
using namespace std;
//带默认参数的函数
//void func(int n, float b=1.2, char c='@')
//{
//	cout<<n<<", "<<b<<", "<<c<<endl;
//}

//除了使用数值常量指定，也可以使用表达式指定

//一旦为某个形参指定了默认值，那么它后面的所有形参都必须有默认值
float d = 10.8;
void func(int n, float b=d+2.9, char c='@')
{
	cout<<n<<", "<<b<<", "<<c<<endl;
}

int main(){
	//为所有参数传值
	func(10, 3.5, '#');
	//为n、b传值，相当于调用func(20, 9.8, '@')
	func(20, 9.8);
	//只为n传值，相当于调用func(30, 1.2, '@')
	func(30);
	return 0;
}