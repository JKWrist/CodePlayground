#include <iostream>
using namespace std;
//基类
class Base
{
public:
	Base();
	~Base();
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
class Derived: public Base
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

int main()
{
	Base *pb = new Derived();
	delete pb;
	//在本例中，不调用派生类的析构函数会导致 name 指向的 100 个 char 类型的内存空间得不到释放；除非程序运行结束由操作系统回收，否则就再也没有机会释放这些内存。这是典型的内存泄露。
	cout<<"-------------------"<<endl;
	cout<<"-------------------"<<endl;
	cout<<"-------------------"<<endl;
	Derived *pd = new Derived();
	delete pd;
	return 0;
}