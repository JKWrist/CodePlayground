#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
template<typename T, int N>

//C/C++ 规定，数组一旦定义后，它的长度就不能改变了；换句话说，数组容量不能动态地增大或者减小。这样的数组称为静态数组（Static array）。静态数组有时候会给编码代码不便，我们可以通过自定义的 Array 类来实现动态数组（Dynamic array）。所谓动态数组，是指数组容量能够在使用的过程中随时增大或减小
class Array
{
public:
	Array();
	~Array();
public:
	T & operator[](int i);  //重载下标运算符[]
	int length() const 
	{ 
		return m_length; 
	}  //获取数组长度
	
	bool capacity(int n);  //改变数组容量
private:
	int m_length;  //数组的当前长度
	int m_capacity;  //当前内存的容量（能容纳的元素的个数）
	T *m_p;  //指向数组内存的指针
};

template<typename T, int N>
Array<T, N>::Array()
{
	m_p = new T[N];
	m_capacity = m_length = N;
}

template<typename T, int N>
Array<T, N>::~Array()
{
	delete[] m_p;
}

template<typename T, int N>
T & Array<T, N>::operator[](int i)
{
	if(i<0 || i>=m_length)
	{
		cout<<"Exception: Array index out of bounds!"<<endl;
	}
	return m_p[i];
}

template<typename T, int N>
bool Array<T, N>::capacity(int n)
{
	if(n > 0)
	{  
		//增大数组
		int len = m_length + n;  //增大后的数组长度
		if(len <= m_capacity)
		{  
			//现有内存足以容纳增大后的数组
			m_length = len;
			return true;
		}
		else
		{  
			//现有内存不能容纳增大后的数组
			T *pTemp = new T[m_length + 2 * n * sizeof(T)];  //增加的内存足以容纳 2*n 个元素
			if(pTemp == NULL)
			{  
				//内存分配失败
				cout<<"Exception: Failed to allocate memory!"<<endl;
				return false;
			}
			else
			{  
				//内存分配成功
				memcpy( pTemp, m_p, m_length*sizeof(T) );
				delete[] m_p;
				m_p = pTemp;
				m_capacity = m_length = len;
			}
		}
	}
	else
	{  
		//收缩数组
		int len = m_length - abs(n);  //收缩后的数组长度
		if(len < 0)
		{
			cout<<"Exception: Array length is too small!"<<endl;
			return false;
		}
		else
		{
			m_length = len;
			return true;
		}
	}
}

int main()
{
	Array<int, 5> arr;
	//为数组元素赋值
	for(int i=0, len=arr.length(); i<len; i++)
	{
		arr[i] = 2*i;
	}

	//第一次打印数组
	for(int i=0, len=arr.length(); i<len; i++)
	{
		cout << arr[i] << " ";
	}
	cout<<endl;

	//扩大容量并为增加的元素赋值
	arr.capacity(8);
	for(int i = 5, len = arr.length(); i < len; i++)
	{
		arr[i] = 2 * i;
	}
	
	//第二次打印数组
	for(int i=0, len=arr.length(); i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//收缩容量
	arr.capacity(-4);
	//第三次打印数组
	for(int i=0, len=arr.length(); i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}