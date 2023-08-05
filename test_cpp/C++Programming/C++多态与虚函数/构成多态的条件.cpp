#include <iostream>
using namespace std;
//基类Base
class Base
{
public:
	virtual void func();
	virtual void func(int);
};
void Base::func()
{
	cout<<"void Base::func()"<<endl;
}

void Base::func(int n)
{
	cout<<"void Base::func(int)"<<endl;
}

//派生类Derived
class Derived: public Base
{
public:
	void func();
	void func(char *);
};

void Derived::func()
{
	cout<<"void Derived::func()"<<endl;
}

void Derived::func(char *str)
{
	cout<<"void Derived::func(char *)"<<endl;
}

int main()
{
	Derived *p1 = new Derived();
	p1 -> func();  //输出void Derived::func()
	//p -> func(10);  //输出void Base::func(int)
	p1 -> func("http://c.biancheng.net");  //compile error
	//因为通过基类的指针只能访问从基类继承过去的成员，不能访问派生类新增的成员。
	cout << endl;
	
	Base *p2 = new Derived();
	p2 -> func();  //输出void Derived::func()
	p2 -> func(10);  //输出void Base::func(int)
	//p -> func("http://c.biancheng.net");  //compile error
	//因为通过基类的指针只能访问从基类继承过去的成员，不能访问派生类新增的成员。
	return 0;
}