#include <string.h>
#include "myArray.h"

//默认构造，初始为100字节的数组
MyArray::MyArray()
{
	cout << "默认构造函数" << endl;
	this->m_Capacity = 100;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
}

//有参构造函数
MyArray::MyArray(int capacity)
{
	cout << "有参构造函数" << endl;
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAddress = new int[capacity];
}

//拷贝构造
MyArray::MyArray(const MyArray & arr)
{
	cout << "拷贝构造" << endl;
	this->m_Capacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	this->pAddress = new int[arr.m_Capacity];
	
	for(int i = 0; i < m_Size; i++)
	{
		pAddress[i] = arr.pAddress[i];
	}
}

//尾插法
void MyArray::pushBack(int val)
{
	this->pAddress[m_Size] = val;
	this->m_Size++;
}

//根据位置设置数据
void MyArray::setData(int pos, int val)
{
	if(pos >= 0 && pos <= m_Capacity - 1)
	{
		this->pAddress[pos] = val;
	}
}

//根据位置获取数据
int MyArray::getData(int pos)
{
	return this->pAddress[pos];
}

//获取数组容量
int MyArray::getCapacity()
{
	return this->m_Capacity;
}

//获取数组大小
int MyArray::getSize()
{
	return this->m_Size;
}

//析构
MyArray::~MyArray()
{
	if(pAddress != NULL)
	{
		cout << "析构函数调用" << endl;
		delete []pAddress;
		pAddress = NULL;
	}
}

//重载[]运算符
int& MyArray::operator[](int index)
{
	if(index >= 0 && index <= m_Capacity - 1)
	{
		return this->pAddress[index];
	}
}