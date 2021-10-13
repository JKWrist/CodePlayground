#include <iostream>
using namespace std;

//虚基类A
class A
{
public:
	A(int a);
protected:
	int m_a;
};
A::A(int a): m_a(a){ }


//直接派生类B
class B: virtual public A
{
public:
	B(int a, int b);
public:
	void display();
protected:
	int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display(){
	cout<<"m_a="<<m_a<<", m_b="<<m_b<<endl;
}


//直接派生类C
class C: virtual public A
{
public:
	C(int a, int c);
public:
	void display();
protected:
	int m_c;
};
C::C(int a, int c): A(a), m_c(c){ }
void C::display()
{
	cout<<"m_a="<<m_a<<", m_c="<<m_c<<endl;
}


//间接派生类D
class D: public B, public C
{
public:
	D(int a, int b, int c, int d);
public:
	void display();
private:
	int m_d;
};

//D::D(int a, int b, int c, int d)
//: A(a)
//, B(90, b)
//, C(100, c)
//, m_d(d)
//{ }
//现在采用了虚继承，虚基类 A 在最终派生类 D 中只保留了一份成员变量 m_a，如果由 B 和 C 初始化 m_a，那么 B 和 C 在调用 A 的构造函数时很有可能给出不同的实参，这个时候编译器就会犯迷糊，不知道使用哪个实参初始化 m_a。

//为了避免出现这种矛盾的情况，C++ 干脆规定必须由最终的派生类 D 来初始化虚基类 A，直接派生类 B 和 C 对 A 的构造函数的调用是无效的。在第 50 行代码中，调用 B 的构造函数时试图将 m_a 初始化为 90，调用 C 的构造函数时试图将 m_a 初始化为 100，但是输出结果有力地证明了这些都是无效的，m_a 最终被初始化为 50，这正是在 D 中直接调用 A 的构造函数的结果。


//虚继承时构造函数的执行顺序与普通继承时不同：在最终派生类的构造函数调用列表中，不管各个构造函数出现的顺序如何，编译器总是先调用虚基类的构造函数，再按照出现的顺序调用其他的构造函数；而对于普通继承，就是按照构造函数出现的顺序依次调用的。

D::D(int a, int b, int c, int d)
: B(90, b)
, C(100, c)
, A(a)
, m_d(d)
{ }

void D::display()
{
	cout<<"m_a="<<m_a<<", m_b="<<m_b<<", m_c="<<m_c<<", m_d="<<m_d<<endl;
}


int main()
{
	B b(10, 20);
	b.display();
	C c(30, 40);
	c.display();
	D d(50, 60, 70, 80);
	d.display();
	return 0;
}