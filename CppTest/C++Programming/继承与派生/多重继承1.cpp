#include <iostream>
using namespace std;

//基类
class BaseA
{
public:
	BaseA(int a, int b);
	~BaseA();
protected:
	int m_a;
	int m_b;
};
BaseA::BaseA(int a, int b): m_a(a), m_b(b){
	cout<<"BaseA constructor"<<endl;
}
BaseA::~BaseA(){
	cout<<"BaseA destructor"<<endl;
}


//基类
class BaseB{
public:
	BaseB(int c, int d);
	~BaseB();
protected:
	int m_c;
	int m_d;
};
BaseB::BaseB(int c, int d): m_c(c), m_d(d){
	cout<<"BaseB constructor"<<endl;
}
BaseB::~BaseB(){
	cout<<"BaseB destructor"<<endl;
}


//派生类
class Derived: public BaseA, public BaseB
{
public:
	Derived(int a, int b, int c, int d, int e);
	~Derived();
public:
	void show();
private:
	int m_e;
};
Derived::Derived(int a, int b, int c, int d, int e)
: BaseA(a, b)
, BaseB(c, d)
, m_e(e)
{
	cout<<"Derived constructor"<<endl;
}
Derived::~Derived()
{
	cout<<"Derived destructor"<<endl;
}
void Derived::show()
{
	cout<<m_a<<", "<<m_b<<", "<<m_c<<", "<<m_d<<", "<<m_e<<endl;
}


int main()
{
	Derived obj(1, 2, 3, 4, 5);
	obj.show();
	return 0;
}