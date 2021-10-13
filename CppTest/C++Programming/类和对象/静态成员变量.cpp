//1.父类的static变量和函数在派生类中依然可用，但是受访问性控制（比如，父类的private域中的就不可访问），而且对static变量来说，派生类和父类中的static变量是共用空间的，这点在利用static变量进行引用计数的时候要特别注意。   
//2.static函数没有“虚函数”一说。因为static函数实际上是“加上了访问控制的全局函数”，全局函数哪来的什么虚函数？   
//3.派生类的friend函数可以访问派生类本身的一切变量，包括从父类继承下来的protected域中的变量。但是对父类来说，他并不是friend的。

#include<iostream>  
using namespace std;  
class A  
{  
public:  
	static int num;  
};  
int A::num=100;  

class B:public A  
{  
public:  
	int i;  
	B(int m):i(m)  
	{}  
};  

//int B::num=200;  
int main()  
{  
	B b(5);  

	cout << b.num << endl;  
	b.num = 10;  
	cout << b.num << endl;  
	cout << B::num << endl;  
	cout << A::num << endl ;  

	cout << &B::num << endl;  
	cout << &A::num << endl;  
	cout << &b.num << endl;  

//所以父类子类指向是同一个全局数据区的static变量。此外 如果定义 int B::num=200; 会出现编译错误。

	return 0;  
}  