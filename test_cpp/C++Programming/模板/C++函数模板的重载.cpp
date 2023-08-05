#include <iostream>
using namespace std;

template<class T> void Swap(T &a, T &b);  //模板①：交换基本类型的值

template<typename T> void Swap(T a[], T b[], int len);  //模板②：交换两个数组

void printArray(int arr[], int len);  //打印数组元素

int main()
{
	//交换基本类型的值
	int m = 10, n = 99;
	
	Swap(m, n);  //匹配模板①
	cout << m << ", " << n << endl;
	
	float m1 = 11.1, n1 = 99.1;
	Swap(m1, n1);  //匹配模板①
	cout << m1 << ", " << n1 << endl;
		
	//交换两个数组
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 10, 20, 30, 40, 50 };
	
	int len = sizeof(a) / sizeof(int);  //数组长度
	
	Swap(a, b, len);  //匹配模板②
	printArray(a, len);
	printArray(b, len);
	return 0;
}

template<class T> 
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;	
}

//重点
//形参 len 用来指明要交换的数组的长度，调用 Swap() 函数之前必须先通过sizeof求得数组长度再传递给它
template<typename T> void Swap(T a[], T b[], int len)
{
	T temp;
	for(int i=0; i<len; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void printArray(int arr[], int len)
{
	for(int i=0; i<len; i++)
	{
		if(i == len-1)
		{
			cout << arr[i] << endl;
		}
		else
		{
			cout << arr[i] << ", ";
		}
	}
}