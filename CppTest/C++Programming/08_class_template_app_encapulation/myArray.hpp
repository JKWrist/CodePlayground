#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

template <class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[capacity];
	}

	//拷贝构造
	MyArray(const MyArray & arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for(int i = 0; i < m_Capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//重载=
	MyArray & operator=(const MyArray & arr)
	{
		if(pAddress != NULL)
		{
			delete [] pAddress;
			pAddress = NULL;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for(int i = 0; i < m_Capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//重载[]
	T & operator[](int index)
	{
		return pAddress[index];
	}

	//尾插法
	void pushBack(const T & val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		pAddress[m_Size] = val;
		m_Size++;
	}

	//获取数组容量
	int getCapacity()
	{
		return m_Capacity;
	}

	//获取数组大小
	int getSize()
	{
		return m_Size;
	}

	//析构
	~MyArray()
	{
		if(pAddress != NULL)
		{
			delete [] pAddress;
			pAddress = NULL;
		}
		this->m_Capacity = 0;
		this->m_Size = 0;
	}
private:
	T * pAddress; 	//指向堆区的真实数组指针
	int m_Capacity;	//数组容量
	int m_Size;		//数组大小
};