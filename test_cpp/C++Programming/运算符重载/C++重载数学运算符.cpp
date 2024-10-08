#include <iostream>
#include <cmath>

using namespace std;
//四则运算符（+、-、*、/、+=、-=、*=、/=）和关系运算符（>、<、<=、>=、==、!=）都是数学运算符，它们在实际开发中非常常见，被重载的几率也很高，并且有着相似的重载格式。本节以复数类 Complex 为例对它们进行重载，重在演示运算符重载的语法以及规范。
//
//复数能够进行完整的四则运算，但不能进行完整的关系运算：我们只能判断两个复数是否相等，但不能比较它们的大小，所以不能对 >、<、<=、>= 进行重载。下面是具体的代码：

//需要注意的是，我们以全局函数的形式重载了 +、-、*、/、==、!=，以成员函数的形式重载了 +=、-=、*=、/=，而且应该坚持这样做，不能一股脑都写作成员函数或者全局函数，具体原因我们将在下节《到底以成员函数还是全局函数（友元函数）的形式重载运算符》讲解。

//复数类
class Complex{
public:  //构造函数
	Complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag)
	{
		
	}
public:  //运算符重载
	//以全局函数的形式重载
	friend Complex operator+(const Complex &c1, const Complex &c2);
	friend Complex operator-(const Complex &c1, const Complex &c2);
	friend Complex operator*(const Complex &c1, const Complex &c2);
	friend Complex operator/(const Complex &c1, const Complex &c2);
	friend bool operator==(const Complex &c1, const Complex &c2);
	friend bool operator!=(const Complex &c1, const Complex &c2);
	//以成员函数的形式重载
	//C++ 规定，箭头运算符->、下标运算符[ ]、函数调用运算符( )、赋值运算符=只能以  成员函数 的形式重载。
	Complex & operator+=(const Complex &c);
	Complex & operator-=(const Complex &c);
	Complex & operator*=(const Complex &c);
	Complex & operator/=(const Complex &c);
public:  //成员函数
	double real() const{ return m_real; }
	double imag() const{ return m_imag; }
private:
	double m_real;  //实部
	double m_imag;  //虚部
};
//重载+运算符
Complex operator+(const Complex &c1, const Complex &c2){
	Complex c;
	c.m_real = c1.m_real + c2.m_real;
	c.m_imag = c1.m_imag + c2.m_imag;
	cout<<"operator+(const Complex &c1, const Complex &c2)"<<endl;
	return c;
}
//重载-运算符
Complex operator-(const Complex &c1, const Complex &c2){
	Complex c;
	c.m_real = c1.m_real - c2.m_real;
	c.m_imag = c1.m_imag - c2.m_imag;
	cout<<"operator-(const Complex &c1, const Complex &c2)"<<endl;
	return c;
}
//重载*运算符  (a+bi) * (c+di) = (ac-bd) + (bc+ad)i
Complex operator*(const Complex &c1, const Complex &c2){
	Complex c;
	c.m_real = c1.m_real * c2.m_real - c1.m_imag * c2.m_imag;
	c.m_imag = c1.m_imag * c2.m_real + c1.m_real * c2.m_imag;
	cout<<"operator*(const Complex &c1, const Complex &c2)"<<endl;
	return c;
}
//重载/运算符  (a+bi) / (c+di) = [(ac+bd) / (c²+d²)] + [(bc-ad) / (c²+d²)]i
Complex operator/(const Complex &c1, const Complex &c2){
	Complex c;
	c.m_real = (c1.m_real*c2.m_real + c1.m_imag*c2.m_imag) / (pow(c2.m_real, 2) + pow(c2.m_imag, 2));
	c.m_imag = (c1.m_imag*c2.m_real - c1.m_real*c2.m_imag) / (pow(c2.m_real, 2) + pow(c2.m_imag, 2));
	cout<<"operator/(const Complex &c1, const Complex &c2)"<<endl;
	return c;
}
//重载==运算符
bool operator==(const Complex &c1, const Complex &c2){
	cout<<"operator==(const Complex &c1, const Complex &c2)"<<endl;
	if( c1.m_real == c2.m_real && c1.m_imag == c2.m_imag )
	{
		return true;
	}
	else
	{
		return false;
	}
}
//重载!=运算符
bool operator!=(const Complex &c1, const Complex &c2){
	cout<<"operator!=(const Complex &c1, const Complex &c2)"<<endl;
	if( c1.m_real != c2.m_real || c1.m_imag != c2.m_imag )
	{
		return true;
	}
	else
	{
		return false;
	}
}
//重载+=运算符
Complex & Complex::operator+=(const Complex &c){
	cout<<"operator+=(const Complex &c)"<<endl;
	this->m_real += c.m_real;
	this->m_imag += c.m_imag;
	return *this;
}
//重载-=运算符
Complex & Complex::operator-=(const Complex &c){
	cout<<"operator-=(const Complex &c)"<<endl;
	this->m_real -= c.m_real;
	this->m_imag -= c.m_imag;
	return *this;
}
//重载*=运算符
Complex & Complex::operator*=(const Complex &c){
	cout<<"operator*=(const Complex &c)"<<endl;
	this->m_real = this->m_real * c.m_real - this->m_imag * c.m_imag;
	this->m_imag = this->m_imag * c.m_real + this->m_real * c.m_imag;
	return *this;
}
//重载/=运算符
Complex & Complex::operator/=(const Complex &c){
	this->m_real = (this->m_real*c.m_real + this->m_imag*c.m_imag) / (pow(c.m_real, 2) + pow(c.m_imag, 2));
	this->m_imag = (this->m_imag*c.m_real - this->m_real*c.m_imag) / (pow(c.m_real, 2) + pow(c.m_imag, 2));
	return *this;
}
int main(){
	Complex c1(25, 35);
	Complex c2(10, 20);
	Complex c3(1, 2);
	Complex c4(4, 9);
	Complex c5(34, 6);
	Complex c6(80, 90);
   
	Complex c7 = c1 + c2;
	Complex c8 = c1 - c2;
	Complex c9 = c1 * c2;
	Complex c10 = c1 / c2;
	cout<<"c7 = "<<c7.real()<<" + "<<c7.imag()<<"i"<<endl;
	cout<<"c8 = "<<c8.real()<<" + "<<c8.imag()<<"i"<<endl;
	cout<<"c9 = "<<c9.real()<<" + "<<c9.imag()<<"i"<<endl;
	cout<<"c10 = "<<c10.real()<<" + "<<c10.imag()<<"i"<<endl;
   
	c3 += c1;
	c4 -= c2;
	c5 *= c2;
	c6 /= c2;
	cout<<"c3 = "<<c3.real()<<" + "<<c3.imag()<<"i"<<endl;
	cout<<"c4 = "<<c4.real()<<" + "<<c4.imag()<<"i"<<endl;
	cout<<"c5 = "<<c5.real()<<" + "<<c5.imag()<<"i"<<endl;
	cout<<"c6 = "<<c6.real()<<" + "<<c6.imag()<<"i"<<endl;

	if(c1 == c2)
	{
		cout<<"c1 == c2"<<endl;
	}
	if(c1 != c2)
	{
		cout<<"c1 != c2"<<endl;
	}

	return 0;
}