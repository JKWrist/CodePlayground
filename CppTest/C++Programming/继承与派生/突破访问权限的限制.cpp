#include <iostream>
using namespace std;
class A{
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
	int a1 = *(int*)&obj;
	int b = *(int*)( (int)&obj + sizeof(int) );
	A * p = new A(40, 50, 60);
	int a2 = *(int*)p;
	int c = *(int*)( (int)p + sizeof(int)*2 );

	cout<<"a1="<<a1<<", a2="<<a2<<", b="<<b<<", c="<<c<<endl;
	return 0;
}