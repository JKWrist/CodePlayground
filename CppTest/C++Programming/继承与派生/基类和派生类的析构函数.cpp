#include <iostream>
using namespace std;
class A
{
public:
	A(){cout<<"A constructor"<<endl;}
	~A(){cout<<"A destructor"<<endl;}
};


class B: public A
{
public:
	B(){cout<<"B constructor"<<endl;}
	~B(){cout<<"B destructor"<<endl;}
};


class C: public B
{
public:
	C(){cout<<"C constructor"<<endl;}
	~C(){cout<<"C destructor"<<endl;}
};
//创建派生类对象时，构造函数的执行顺序和继承顺序相同，即先执行基类构造函数，再执行派生类构造函数。
//而销毁派生类对象时，析构函数的执行顺序和继承顺序相反，即先执行派生类析构函数，再执行基类析构函数。

int main()
{
	C test;
	return 0;
}