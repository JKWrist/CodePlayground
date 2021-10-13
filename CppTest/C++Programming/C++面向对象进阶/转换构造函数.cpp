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
		cout << "Complex()" << endl;
	}
	
	Complex(double real, double imag)
	: m_real(real)
	, m_imag(imag)
	{ 
		cout << "Complex(double real, double imag)" << endl;
	}
	
	Complex(double real)
	: m_real(real)
	, m_imag(0.0)
	{ 
		cout << "Complex(double real)" << endl;
	}  //转换构造函数
public:
	friend ostream & operator<<(ostream &out, Complex &c);  //友元函数
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

int main()
{
	Complex a(10.0, 20.0);
	cout << a << endl;
	a = 25.5;  //调用转换构造函数
	cout << a << endl;
	
	
	//转换构造函数也是构造函数的一种，它除了可以用来将其它类型转换为当前类类型，还可以用来初始化对象，这是构造函数本来的意义。
	Complex c1(26.4);  //创建具名对象
	Complex c2 = 240.3;  //以拷贝的方式初始化对象
	Complex(15.9);  //创建匿名对象
	c1 = Complex(46.9);  //创建一个匿名对象并将它赋值给 c1
	
	return 0;
}