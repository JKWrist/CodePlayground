#include <iostream>
//模板不会占用内存，最终生成的函数或者类才会占用内存。由模板生成函数或类的过程叫做模板的实例化（Instantiate），相应地，针对某个类型生成的特定版本的函数或类叫做模板的一个实例（Instantiation）。
using namespace std;

template<typename T> void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n1 = 100, n2 = 200, n3 = 300, n4 = 400;
	float f1 = 12.5, f2 = 56.93;
   
	Swap(n1, n2);  //T为int，实例化出 void Swap(int &a, int &b);
	Swap(f1, f2);  //T为float，实例化出 void Swap(float &a, float &b);
	Swap(n3, n4);  //T为int，调用刚才生成的 void Swap(int &a, int &b);
	return 0;
}