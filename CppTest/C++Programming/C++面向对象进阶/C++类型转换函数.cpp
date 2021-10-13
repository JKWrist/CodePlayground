#include <iostream>
using namespace std;
//复数类
class Complex{
public:
	Complex(): m_real(0.0), m_imag(0.0){ }
	Complex(double real, double imag): m_real(real), m_imag(imag){ }
public:
	friend ostream & operator<<(ostream &out, Complex &c);
	friend Complex operator+(const Complex &c1, const Complex &c2);
	//type 可以是内置类型、类类型以及由 typedef 定义的类型别名，任何可作为函数返回类型的类型（void 除外）都能够被支持。一般而言，不允许转换为数组或函数类型，转换为指针类型或引用类型是可以的。
	//类型转换函数一般不会更改被转换的对象，所以通常被定义为 const 成员。
	//类型转换函数可以被继承，可以是虚函数。
	operator double() const 
	{ 
		cout << "perator double() const " << endl;
		return m_real; 
	}  //类型转换函数
private:
	double m_real;  //实部
	double m_imag;  //虚部
};

//重载>>运算符
ostream & operator<<(ostream &out, Complex &c)
{
	cout << "ostream & operator<<(ostream &out, Complex &c)" << endl;
	out << c.m_real << " + " << c.m_imag << "i";;
	return out;
}

//重载+运算符
Complex operator+(const Complex &c1, const Complex &c2)
{
	cout << "Complex operator+(const Complex &c1, const Complex &c2)" << endl;
	Complex c;
	c.m_real = c1.m_real + c2.m_real;
	c.m_imag = c1.m_imag + c2.m_imag;
	return c;
}

int main()
{
	Complex c1(24.6, 100);
	double f = c1;  //相当于 double f = Complex::operator double(&c1);
	cout << "f = " << f << endl;
	
	f = 12.5 + c1 + 6;  //相当于 f = 12.5 + Complex::operator double(&c1) + 6;
	cout << "f = " << f << endl;
	
	int n = Complex(43.2, 9.3);  //先转换为 double，再转换为 int
	cout << "n = " << n << endl;
	
	return 0;
}