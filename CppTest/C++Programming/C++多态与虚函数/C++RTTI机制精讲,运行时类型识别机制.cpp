//C++ 的对象内存模型主要包含了以下几个方面的内容：
//1、如果没有虚函数也没有虚继承，那么对象内存模型中只有成员变量。
//2、如果类包含了虚函数，那么会额外添加一个虚函数表，并在对象内存中插入一个指针，指向这个虚函数表。
//3、如果类包含了虚继承，那么会额外添加一个虚基类表，并在对象内存中插入一个指针，指向这个虚基类表。

#include <iostream>
using namespace std;

//基类
class Base{
public:
	virtual void func();
protected:
	int m_a;
	int m_b;
};
void Base::func(){ cout<<"Base"<<endl; }


//派生类
class Derived: public Base{
public:
	void func();
private:
	int m_c;
};
void Derived::func(){ cout<<"Derived"<<endl; }
int main()
{
	Base *p;
	int n;

	cin>>n;
	if(n <= 100)
	{
		cout << "1" << endl;
		p = new Base();
	}
	else
	{
		cout << "2" << endl;
		p = new Derived();
	}
	cout << "3" << endl;
	cout<<typeid(*p).name()<<endl;
	cout << "4" << endl;
	return 0;
}