#include <iostream>

using namespace std;
//在C++中，数据的类型也可以通过参数来传递，在函数定义时可以不指明具体的数据类型，当发生函数调用时，编译器可以根据传入的实参自动推断数据类型。这就是类型的参数化。

//所谓函数模板，实际上是建立一个通用函数，它所用到的数据的类型（包括返回值类型、形参类型、局部变量类型）可以不具体指定，而是用一个虚拟的类型来代替（实际上是用一个标识符来占位），等发生函数调用时再根据传入的实参来逆推出真正的类型。这个通用函数就称为函数模板（Function Template）。

//一但定义了函数模板，就可以将类型参数用于函数定义和函数声明了。说得直白一点，原来使用 int、float、char 等内置类型的地方，都可以用类型参数来代替。

#include <iostream>
using namespace std;

//template是定义函数模板的关键字，它后面紧跟尖括号<>，尖括号包围的是类型参数（也可以说是虚拟的类型，或者说是类型占位符）。
//typename是另外一个关键字，用来声明具体的类型参数，这里的类型参数就是T。从整体上看，template<typename T>被称为模板头。

template<typename T> void Swap(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
	cout << "555" << endl;
}

////交换 int 变量的值
//void Swap(int *a, int *b){
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//	cout << "111" << endl;
//}
////交换 float 变量的值
//void Swap(float *a, float *b){
//	float temp = *a;
//	*a = *b;
//	*b = temp;
//	cout << "222" << endl;
//}
////交换 char 变量的值
//void Swap(char *a, char *b){
//	char temp = *a;
//	*a = *b;
//	*b = temp;
//	cout << "333" << endl;
//}
////交换 bool 变量的值
//void Swap(bool *a, bool *b){
//	char temp = *a;
//	*a = *b;
//	*b = temp;
//	cout << "444" << endl;
//}



int main(){
	//交换 int 变量的值
	int n1 = 100, n2 = 200;
	Swap(&n1, &n2);
	cout<<n1<<", "<<n2<<endl;
   
	//交换 float 变量的值
	float f1 = 12.5, f2 = 56.93;
	Swap(&f1, &f2);
	cout<<f1<<", "<<f2<<endl;
   
	//交换 char 变量的值
	char c1 = 'A', c2 = 'B';
	Swap(&c1, &c2);
	cout<<c1<<", "<<c2<<endl;
   
	//交换 bool 变量的值
	bool b1 = false, b2 = true;
	Swap(&b1, &b2);
	cout<<b1<<", "<<b2<<endl;
	return 0;
}