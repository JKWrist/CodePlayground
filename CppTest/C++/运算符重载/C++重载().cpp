#include <iostream>
using namespace std;

class Complex
{
private:
	double real, imag;
public:
	Complex(double r = 0, double i = 0)
	: real(r)
	, imag(i) 
	{
		
	};
	//重载强制类型转换运算符时，不需要指定返回值类型，因为返回值类型是确定的，就是运算符本身代表的类型，在这里就是 double。
	//重载强制类型转换运算符 double
	operator double() 
	{ 
		return real; 
	}  
};

int main()
{
	Complex c(1.2, 3.4);
	cout << (double)c << endl;  //输出 1.2
	double n = 2 + c;  			//等价于 double n = 2 + c. operator double()
	cout << n << endl;  	   	//输出 3.2
	
	n = c + 5;
	cout << n << endl;
}