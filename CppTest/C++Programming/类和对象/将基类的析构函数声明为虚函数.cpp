#include <iostream>
using namespace std;
//基类
class Base{
public:
	Base();
	virtual ~Base();
protected:
	char *str;
};

Base::Base()
{
	str = new char[100];
	cout<<"Base constructor"<<endl;
}
Base::~Base()
{
	delete[] str;
	cout<<"Base destructor"<<endl;
}
//派生类
class Derived
: public Base
{
public:
	Derived();
	~Derived();
private:
	char *name;
};
Derived::Derived()
{
	name = new char[100];
	cout<<"Derived constructor"<<endl;
}
Derived::~Derived()
{
	delete[] name;
	cout<<"Derived destructor"<<endl;
}
//pb、pd 都指向了派生类的对象，所以会调用派生类的析构函数，继而再调用基类的析构函数。如此一来也就解决了内存泄露的问题。
//如果这个类又是一个基类，那么我们就必须将该析构函数声明为虚函数，否则就有内存泄露的风险。也就是说，大部分情况下都应该将基类的析构函数声明为虚函数。
int main()
{
   Base *pb = new Derived();
   delete pb;
   cout<<"-------------------"<<endl;
   Derived *pd = new Derived();
   delete pd;
   return 0;
}