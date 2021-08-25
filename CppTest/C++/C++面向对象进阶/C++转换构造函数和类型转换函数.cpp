#include <iostream>
using namespace std;

//复数类
class Complex
{
public:
	Complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag){ }  //包含了转换构造函数
public:
	friend ostream & operator<<(ostream &out, Complex &c);
	friend Complex operator+(const Complex &c1, const Complex &c2);
	operator double() const { return m_real; }  //类型转换函数
private:
	double m_real;  //实部
	double m_imag;  //虚部
};

//重载>>运算符
ostream & operator<<(ostream &out, Complex &c)
{
	out << c.m_real <<" + "<< c.m_imag <<"i";;
	return out;
}

//重载+运算符
Complex operator+(const Complex &c1, const Complex &c2)
{
	Complex c;
	c.m_real = c1.m_real + c2.m_real;
	c.m_imag = c1.m_imag + c2.m_imag;
	return c;
}
int main()
{
	Complex c1(24.6, 100);
	//double f = c1;  //①正确，调用类型转换函数
	//c1 = 78.4;  //②正确，调用转换构造函数
	//f = 12.5 + c1;  //③错误，产生二义性
	//Complex c2 = c1 + 46.7;  //④错误，产生二义性
	return 0;
}