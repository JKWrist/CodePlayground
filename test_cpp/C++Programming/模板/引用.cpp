#include <iostream>
using namespace std;

//下面我们来总结一下定义模板函数的语法：
//template <typename 类型参数1 , typename 类型参数2 , ...> 返回值类型  函数名(形参列表){
//	//在函数体中可以使用类型参数
//}

//typename关键字也可以使用class关键字替代，它们没有任何区别。C++ 早期对模板的支持并不严谨，没有引入新的关键字，而是用 class 来指明类型参数，但是 class 关键字本来已经用在类的定义中了，这样做显得不太友好，所以后来 C++ 又引入了一个新的关键字 typename，专门用来定义类型参数。不过至今仍然有很多代码在使用 class 关键字，包括 C++ 标准库、一些开源程序等。

//template<class T> void Swap(T &a, T &b){
//	T temp = a;
//	a = b;
//	b = temp;
//}

template<typename T> void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


int main(){
	//交换 int 变量的值
	int n1 = 100, n2 = 200;
	Swap(n1, n2);
	cout<<n1<<", "<<n2<<endl;
   
	//交换 float 变量的值
	float f1 = 12.5, f2 = 56.93;
	Swap(f1, f2);
	cout<<f1<<", "<<f2<<endl;
   
	//交换 char 变量的值
	char c1 = 'A', c2 = 'B';
	Swap(c1, c2);
	cout<<c1<<", "<<c2<<endl;
   
	//交换 bool 变量的值
	bool b1 = false, b2 = true;
	Swap(b1, b2);
	cout<<b1<<", "<<b2<<endl;
	return 0;
}