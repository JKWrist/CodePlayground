//构造函数与析构函数

#include <iostream>
using namespace std;

class Person
{
public: //构造函数和析构函数必须在声明在全局作用域
	//构造函数
	//1、没有返回值，不用写 void
	//2、函数名与类名相同
	//3、可以有参数，可以发生重载
	//4、构造函数 由编译器自动调用一次，无需手动调用
	Person()
	{
		cout << "Person 的  构造函数调用" << endl;
	}

	//析构函数
	//1、没有返回值 不用写void
	//2、函数名 与类名相同，函数名前加 ~
	//3、不可以有参数，不可以发生重载
	//4、析构函数 也是由编译器自动调用一次，无需手动调用
	~Person()
	{
		cout << "Person 的  析构函数调用" << endl;
	}
};

void test01()
{
	Person p;
}

int main()
{
	test01();

	return 0;
}