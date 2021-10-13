#include <iostream>
using namespace std;

//复数类
class Complex
{
public:  //构造函数
	Complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag){ }  //包含了转换构造函数
public:  //运算符重载
	//以全局函数的形式重载
	friend ostream & operator<<(ostream &out, Complex &c);
	friend istream & operator>>(istream &in, Complex &c);
	friend Complex operator+(const Complex &c1, const Complex &c2);
	friend bool operator==(const Complex &c1, const Complex &c2);
	friend bool operator!=(const Complex &c1, const Complex &c2);
	//以成员函数的形式重载
	Complex & operator+=(const Complex &c);
public:  //成员函数
	double real() const{ return m_real; }
	double imag() const{ return m_imag; }
private:
	double m_real;  //实部
	double m_imag;  //虚部
};

//重载>>运算符
ostream & operator<<(ostream &out, Complex &c)
{
	//cout << "重载>>运算符" << endl << endl;
	out << c.m_real <<" + "<< c.m_imag <<"i";;
	return out;
}

//重载<<运算符
istream & operator>>(istream &in, Complex &c)
{
	cout << "重载<<运算符" << endl << endl;
	in >> c.m_real >> c.m_imag;
	return in;
}

//重载+运算符
Complex operator+(const Complex &c1, const Complex &c2)
{
	cout << "重载+运算符" << endl << endl;
	Complex c;
	c.m_real = c1.m_real + c2.m_real;
	c.m_imag = c1.m_imag + c2.m_imag;
	return c;
}

//重载+=运算符
Complex & Complex::operator+=(const Complex &c)
{
	cout << "重载+=运算符" << endl << endl;
	this->m_real += c.m_real;
	this->m_imag += c.m_imag;
	return *this;
}

//重载==运算符
bool operator==(const Complex &c1, const Complex &c2)
{
	cout << "重载==运算符" << endl << endl;
	if( c1.m_real == c2.m_real && c1.m_imag == c2.m_imag)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//重载!=运算符
bool operator!=(const Complex &c1, const Complex &c2)
{
	cout << "重载!=运算符" << endl << endl;
	if( c1.m_real != c2.m_real || c1.m_imag != c2.m_imag)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	Complex c1(12, 60);
	cout << "c1 = " << c1 << endl << endl;
	
	//先调用转换构造函数将 22.8 转换为 Complex 类型，再调用重载过的 + 运算符
	Complex c2 = c1 + 22.8;
	cout << "c2 = " << c2 << endl << endl;
	
	//同上
	Complex c3 = 8.3 + c1;
	cout << "c3 = "<< c3 << endl << endl;
	
	//先调用转换构造函数将 73 转换为 Complex 类型，再调用重载过的 += 运算符
	Complex c4(4, 19);
	c4 += 73;
	cout << "c4 = " << c4 << endl << endl;
	
	//调用重载过的 += 运算符
	Complex c5(14.6, 26.2);
	c5 += c1;
	cout << "c5 = " << c5 << endl << endl;

	//调用重载过的 == 运算符
	if(c1 == c2)
	{
		cout << "c1 == c2" << endl << endl;
	}
	else
	{
		cout << "c1 != c2" << endl << endl;
	}

	//先调用转换构造函数将 77 转换为 Complex 类型，再调用重载过的 != 运算符
	if(c4 != 77)
	{
		cout << "c4 != 77" << endl << endl;
	}
	else
	{
		cout << "c4 == 77" << endl << endl;
	}
	
	//将 Complex 转换为 double，没有调用类型转换函数，而是调用了 real() 这个普通的成员函数
	double f = c5.real();
	cout<<"f = " << f << endl << endl;
	return 0;
}