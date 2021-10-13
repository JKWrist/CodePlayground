#include <cstdio>
using namespace std;

//基类A
class A
{
public:
	A(int a, int b);
protected:
	int m_a;
	int m_b;
};
A::A(int a, int b): m_a(a), m_b(b){ }


//基类B
class B
{
public:
	B(int b, int c);
protected:
	int m_b;
	int m_c;
};
B::B(int b, int c): m_b(b), m_c(c){ }


//派生类C
class C: public A, public B
{
public:
	C(int a, int b, int c, int d);
public:
	void display();
private:
	int m_a;
	int m_c;
	int m_d;
};
C::C(int a, int b, int c, int d): A(a, b), B(b, c), m_a(a), m_c(c), m_d(d){}
void C::display()
{
	printf("A::m_a=%d, A::m_b=%d\n", A::m_a, A::m_b);
	printf("B::m_b=%d, B::m_c=%d\n", B::m_b, B::m_c);
	printf("C::m_a=%d, C::m_c=%d, C::m_d=%d\n", C::m_a, C::m_c, m_d);
}

int main()
{
	C test(10, 20, 30, 40);
	test.display();
	return 0;
}