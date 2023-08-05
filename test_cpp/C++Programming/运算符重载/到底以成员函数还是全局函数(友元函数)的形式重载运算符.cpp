#include <iostream>
using namespace std;

//复数类
class Complex
{
public:
	Complex()
	: m_real(0.0)
	, m_imag(0.0)
	{ 
		
	}
	
	Complex(double real, double imag)
	: m_real(real)
	, m_imag(imag)
	{ 
		
	}
	
	//转换构造函数
	//Complex(double real);在作为普通构造函数的同时，还能将 double 类型转换为 Complex 类型，集合了“构造函数”和“类型转换”的功能，所以被称为「转换构造函数」。换句话说，转换构造函数用来将其它类型（可以是 bool、int、double 等基本类型，也可以是数组、指针、结构体、类等构造类型）转换为当前类类型。
	Complex(double real)
	: m_real(real)
	, m_imag(0.0)
	{ 
		
	}  
public:
	friend Complex operator+(const Complex &c1, const Complex &c2);
public:
	double real() const
	{ 
		return m_real; 
	}
	
	double imag() const
	{ 
		return m_imag; 
	}
private:
	double m_real;  //实部
	double m_imag;  //虚部
};

//为什么要以全局函数的形式重载 +
//C++ 只会对成员函数的参数进行类型转换，而不会对调用成员函数的对象进行类型转换
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
	Complex c1(25, 35);
	Complex c2 = c1 + 15.6;
	Complex c3 = 28.23 + c1;
	cout<<c2.real()<<" + "<<c2.imag()<<"i"<<endl;
	cout<<c3.real()<<" + "<<c3.imag()<<"i"<<endl;
	return 0;
}