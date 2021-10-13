#include <iostream>
using namespace std;

class complex
{
public:
	complex();
	complex(double real, double imag);
public:
	//声明运算符重载
	complex operator + (const complex &A) const;
	void display() const;
private:
	double m_real;  //实部
	double m_imag;  //虚部
};
complex::complex()
: m_real(0.0)
, m_imag(0.0)
{ 

}

complex::complex(double real, double imag)
: m_real(real)
, m_imag(imag)
{ 

}

//实现运算符重载
complex complex::operator+(const complex &A) const
{
	complex B;
	B.m_real = this->m_real + A.m_real;
	B.m_imag = this->m_imag + A.m_imag;
	return B;
}

void complex::display() const
{
	cout<<m_real<<" + "<<m_imag<<"i"<<endl;
}

int main()
{
	complex c1(4.3, 5.8);
	complex c2(2.4, 3.7);
	complex c3;
	c3 = c1 + c2;
	c3.display();
	return 0;
}
