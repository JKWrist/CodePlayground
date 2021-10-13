#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
//	const int m = 10;
//	int n = m;
	//我们知道，变量是要占用内存的，即使被 const 修饰也不例外。m、n 两个变量占用不同的内存，int n = m;表示将 m 的值赋给 n，这个赋值的过程在C和C++中是有区别的。
	
	const int n = 10;
	int *p = (int*)&n;  //必须强制类型转换
	*p = 99;  //修改const变量的值
	printf("%d\n", n);
	
}