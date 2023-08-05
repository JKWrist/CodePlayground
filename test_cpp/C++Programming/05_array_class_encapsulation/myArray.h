//#program once
#ifndef __MY_ARRAY_H__
#define __MY_ARRAY_H__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class MyArray
{
public:
	MyArray(); //默认构造，初始为100字节的数组

	MyArray(int capacity);//有参构造函数

	MyArray(const MyArray & arr); //拷贝构造

	//尾插法
	void pushBack(int val);

	//根据位置设置数据
	void setData(int pos, int val);

	//根据位置获取数据
	int getData(int pos);

	//获取数组容量
	int getCapacity();

	//获取数组大小
	int getSize();

	//析构
	~MyArray();

	//重载[]运算符
	int & operator[](int index);

private:
	int m_Capacity; //数组容量
	int m_Size; //数组大小
	int *pAddress; //真实在堆区开辟的数组
};

#endif