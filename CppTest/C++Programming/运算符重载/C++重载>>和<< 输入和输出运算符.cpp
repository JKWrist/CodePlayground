#include <iostream>
using namespace std;
class complex
{
public:
	complex(double real = 0.0, double imag = 0.0)
	: m_real(real)
	, m_imag(imag)
	{ 
		
	};
public:
	friend complex operator+(const complex & A, const complex & B);
	friend complex operator-(const complex & A, const complex & B);
	friend complex operator*(const complex & A, const complex & B);
	friend complex operator/(const complex & A, const complex & B);
	//为了能够直接访问 complex 类的 private 成员变量，同样需要将该函数声明为 complex 类的友元函数
	friend istream & operator>>(istream & in, complex & A);
	//运算符重载函数中用到了 complex 类的 private 成员变量，必须在 complex 类中将该函数声明为友元函数
	friend ostream & operator<<(ostream & out, complex & A);
private:
	double m_real;  //实部
	double m_imag;  //虚部
};

//重载加法运算符
complex operator+(const complex & A, const complex &B)
{
	complex C;
	C.m_real = A.m_real + B.m_real;
	C.m_imag = A.m_imag + B.m_imag;
	return C;
}

//重载减法运算符
complex operator-(const complex & A, const complex &B)
{
	complex C;
	C.m_real = A.m_real - B.m_real;
	C.m_imag = A.m_imag - B.m_imag;
	return C;
}

//重载乘法运算符
complex operator*(const complex & A, const complex &B)
{
	complex C;
	C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
	C.m_imag = A.m_imag * B.m_real + A.m_real * B.m_imag;
	return C;
}

//重载除法运算符
complex operator/(const complex & A, const complex & B)
{
	complex C;
	double square = A.m_real * A.m_real + A.m_imag * A.m_imag;
	C.m_real = (A.m_real * B.m_real + A.m_imag * B.m_imag)/square;
	C.m_imag = (A.m_imag * B.m_real - A.m_real * B.m_imag)/square;
	return C;
}

//之所以返回 istream 类对象的引用，是为了能够连续读取复数
//如果不返回引用，那就只能一个一个地读取了
//重载输入运算符
istream & operator>>(istream & in, complex & A)
{
	in >> A.m_real >> A.m_imag;
	return in;
}

//重载输出运算符
ostream & operator<<(ostream & out, complex & A)
{
	out << A.m_real <<" + "<< A.m_imag <<" i ";;
	return out;
}

int main()
{
	complex c1, c2, c3;
	cin>>c1>>c2;
	c3 = c1 + c2;
	cout<<"c1 + c2 = "<<c3<<endl;
	c3 = c1 - c2;
	cout<<"c1 - c2 = "<<c3<<endl;
	c3 = c1 * c2;
	cout<<"c1 * c2 = "<<c3<<endl;
	c3 = c1 / c2;
	cout<<"c1 / c2 = "<<c3<<endl;
	return 0;
}