#include <iostream>
using namespace std;

//基类
class A
{
public:
	A(int a);
public:
	void display();
public:
	int m_a;
};
A::A(int a): m_a(a){ }
void A::display()
{
	cout<<"Class A: m_a = "<< m_a <<endl;
}


//派生类
class B: public A
{
public:
	B(int a, int b);
public:
	void display();
public:
	int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display()
{
	cout<<"Class B: m_a = "<< m_a<<", m_b = "<<m_b<<endl;
}

int main()
{
	A a(10);
	B b(66, 99);
	//赋值前
	a.display();
	b.display();
	cout<<"--------------"<<endl;
	//赋值的本质是将现有的数据写入已分配好的内存中，对象的内存只包含了成员变量，所以对象之间的赋值是成员变量的赋值，成员函数不存在赋值问题
	
	//这种转换关系是不可逆的，只能用派生类对象给基类对象赋值，而不能用基类对象给派生类对象赋值
	//赋值后
	//b = a;
	
	a = b;
	a.display();
	b.display();
	return 0;
}