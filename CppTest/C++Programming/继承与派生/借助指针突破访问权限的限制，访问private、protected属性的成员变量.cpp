#include <iostream>
using namespace std;
class A
{
public:
	A(int a, int b, int c);
private:
	int m_a;
	int m_b;
	int m_c;
};

A::A(int a, int b, int c): m_a(a), m_b(b), m_c(c){ }

int main()
{
	A obj(10, 20, 30);
	int a = obj.m_a;  //Compile Error  declared private here
	A *p = new A(40, 50, 60);
	int b = p->m_b;  //Compile Error
	return 0;
}