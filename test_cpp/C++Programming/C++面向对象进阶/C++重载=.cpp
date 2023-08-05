#include <iostream>
#include <cstdlib>
using namespace std;
//变长数组类
class Array{
public:
	Array(int len);
	Array(const Array &arr);  //拷贝构造函数
	~Array();
public:
	int operator[](int i) const { return m_p[i]; }  //获取元素（读取）
	int &operator[](int i){ return m_p[i]; }  //获取元素（写入）
	//Array & operator=(const Array &arr);  //重载赋值运算符
	int length() const { return m_len; }
private:
	int m_len;
	int *m_p;
};

Array::Array(int len): m_len(len)
{
	m_p = (int*)calloc( len, sizeof(int) );
}

Array::Array(const Array &arr)
{  
	//拷贝构造函数
	this->m_len = arr.m_len;
	this->m_p = (int*)calloc( this->m_len, sizeof(int) );
	memcpy( this->m_p, arr.m_p, m_len * sizeof(int) );
}

Array::~Array()
{ 
	free(m_p); 
}
//对于简单的类，默认的赋值运算符一般就够用了，我们也没有必要再显式地重载它。但是当类持有其它资源时，例如动态分配的内存、打开的文件、指向其他数据的指针、网络连接等，默认的赋值运算符就不能处理了，我们必须显式地重载它，这样才能将原有对象的所有数据都赋值给新对象。

//operator=() 的返回值类型为Array &，这样不但能够避免在返回数据时调用拷贝构造函数，还能够达到连续赋值的目的

//这样不但能够避免在传参时调用拷贝构造函数，还能够同时接收 const 类型和非 const 类型的实参

//Array &Array::operator=(const Array &arr)
//{  
//	//重载赋值运算符
//	if( this != &arr)
//	{  
//		//判断是否是给自己赋值
//		this->m_len = arr.m_len;
//		free(this->m_p);  //释放原来的内存
//		this->m_p = (int*)calloc( this->m_len, sizeof(int) );
//		memcpy( this->m_p, arr.m_p, m_len * sizeof(int) );
//	}
//	return *this;
//}

//打印数组元素
void printArray(const Array &arr)
{
	int len = arr.length();
	for(int i=0; i<len; i++)
	{
		if(i == len-1)
		{
			cout<<arr[i]<<endl;
		}
		else
		{
			cout<<arr[i]<<", ";
		}
	}
}

int main()
{
	Array arr1(10);
	for(int i=0; i<10; i++)
	{
		arr1[i] = i;
	}
	printArray(arr1);
   
	Array arr2(5);
	for(int i=0; i<5; i++)
	{
		arr2[i] = i;
	}
	printArray(arr2);
	
	arr2 = arr1;  //调用operator=()
	printArray(arr2);
	arr2[3] = 234;  //修改arr1的数据不会影响arr2
	arr2[7] = 920;
	printArray(arr1);
   
	return 0;
}