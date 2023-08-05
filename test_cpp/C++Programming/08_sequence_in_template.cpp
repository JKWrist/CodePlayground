#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

template <class T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

//通过一个通用排序，实现对char和int数组的排序，排序顺序从大到小，算法 选择排序
template<class T> //typename 和 class一样
void mySort(T arr[], int len)
{
	int i, j;
	for(i = 0; i < len; i++)
	{
		int max = i;
		for(j = i+1; j < len; j++)
		{
			if(arr[j] > arr[max])
			{
				max = j;
			}
		}

		if(i != max)
		{
			mySwap(arr[i], arr[max]);
		}
	}
	// for (int i = 0; i < len;i++)
	// {
	// 	int max = i;
	// 	for (int j = i + 1; j < len;j++)
	// 	{
	// 		if (arr[max] < arr[j])
	// 		{
	// 			max = j;
	// 		}
	// 	}

	// 	//判断 算出的max和开始认定的i是否一致，如果不同交换数据
	// 	if (i != max)
	// 	{
	// 		mySwap(arr[i], arr[max]);
	// 	}
	// }
}

template<typename T>
void printArray(T array[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}


void test01()
{
	char charArray[] = "helloworld";

	int len = strlen(charArray);
	mySort(charArray, len);
	printArray(charArray, len);

	int intArray[] = {5, 7, 4, 2, 9, 0};
	len = sizeof(intArray)/sizeof(int);
	mySort(intArray, len);
	printArray(intArray, len);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-07 14:35:31
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
