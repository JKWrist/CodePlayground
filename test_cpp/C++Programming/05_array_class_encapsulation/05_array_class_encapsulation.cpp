//数组类封装

#include <iostream>
#include "myArray.h"


void test01()
{
	MyArray arr;

	for(int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}

	for(int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << endl;
	}

	MyArray arr2(arr);
	for(int i = 0; i < arr2.getSize(); i++)
	{
		cout << arr2.getData(i) << endl;
	}

	arr2.setData(0, 1000);
	for(int i = 0; i < arr2.getSize(); i++)
	{
		cout << arr2.getData(i) << endl;
	}
	cout << "int 数组容量为: " << arr2.getCapacity() << endl;
	cout << "int 数组大小为: " << arr2.getSize()     << endl;

}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-13 21:38:12
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	test01();
	return 0;
}
