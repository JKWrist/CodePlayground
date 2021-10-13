#include <iostream>
#include <cstdlib>
using namespace std;
//自定义的异常类型

class OutOfRange
{
public:
	OutOfRange(): m_flag(1){ };
	OutOfRange(int len, int index): m_len(len), m_index(index), m_flag(2){ }
public:
	void what() const;  //获取具体的错误信息
private:
	int m_flag;  //不同的flag表示不同的错误
	int m_len;  //当前数组的长度
	int m_index;  //当前使用的数组下标
};

void OutOfRange::what() const 
{
	if(m_flag == 1)
	{
		cout<<"Error: empty array, no elements to pop."<<endl;
	}
	else if(m_flag == 2)
	{
		cout<<"Error: out of range( array length "<<m_len<<", access index "<<m_index<<" )"<<endl;
	}
	else
	{
		cout<<"Unknown exception."<<endl;
	}
}


//实现动态数组
class Array
{
public:
	Array();
	~Array(){ free(m_p); };
public:
	int operator[](int i) const;  //获取数组元素
	int push(int ele);  //在末尾插入数组元素
	int pop();  //在末尾删除数组元素
	int length() const{ return m_len; };  //获取数组长度
private:
	int m_len;  //数组长度
	int m_capacity;  //当前的内存能容纳多少个元素
	int *m_p;  //内存指针
private:
	static const int m_stepSize = 50;  //每次扩容的步长
};


//Array 类实现了动态数组，它的主要思路是：在创建对象时预先分配出一定长度的内存（通过 malloc() 分配），
//内存不够用时就再扩展内存（通过 realloc() 重新分配）。Array 数组只能在尾部一个一个地插入（通过 push() 插入）或删除（通过 pop() 删除）元素

Array::Array()
{
	m_p = (int*)malloc( sizeof(int) * m_stepSize );
	m_capacity = m_stepSize;
	m_len = 0;
}

int Array::operator[](int index) const 
{
	if(index<0 || index>=m_len ){  //判断是否越界
		throw OutOfRange(m_len, index);  //抛出异常（创建一个匿名对象）
	}
	return *(m_p + index);
}

int Array::push(int ele)
{
	if(m_len >= m_capacity)
	{  
		//如果容量不足就扩容
		m_capacity += m_stepSize;
		m_p = (int*)realloc( m_p, sizeof(int) * m_capacity );  //扩容
	}
	*(m_p + m_len) = ele;
	m_len++;
	return m_len - 1;
}

int Array::pop()
{
	if(m_len == 0)
	{
		throw OutOfRange();  //抛出异常（创建一个匿名对象）
	}
	m_len--;
	return *(m_p + m_len);
}

//打印数组元素
void printArray(Array &arr)
{
	int len = arr.length();
	//判断数组是否为空
	if(len == 0)
	{
		cout<<"Empty array! No elements to print."<<endl;
		return;
	}
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
	Array nums;
	
	//向数组中添加十个元素
	for(int i = 0; i < 10; i++)
	{
		nums.push(i);
	}
	printArray(nums);
	
	//尝试访问第20个元素
	try
	{
		cout << nums[20] << endl;
	}
	catch(OutOfRange &e)
	{
		e.what();
	}
	
	//尝试弹出20个元素
	try
	{
		for(int i=0; i<20; i++)
		{
			nums.pop();
		}
	}
	catch(OutOfRange &e)
	{
		e.what();
	}
	printArray(nums);
	return 0;
}