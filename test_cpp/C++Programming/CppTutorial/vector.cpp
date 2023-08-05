#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;


void test01()
{
	vector<int> v1; // 定义⼀个vector v1，定义的时候没有分配⼤⼩
	cout << v1.size() << endl; // 输出vector v1的⼤⼩，此处应该为0
}

void test02()
{
	cout << "test02" << endl;
#if 1
	vector<int> v(10); // 直接定义⻓度为10的int数组，默认这10个元素值都为0
#else
	vector<int> v;
	v.resize(8); //先定义⼀个vector变量v1，然后将⻓度resize为8，默认这8个元素都是0
#endif
	v[1] = 2;
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

void test03()
{
	cout << "test03" << endl;
	// 在定义的时候就可以对vector变量进⾏初始化
	vector<int> v(100, 9);// 把100⻓度的数组中所有的值都初始化为9
	// 访问的时候像数组⼀样直接⽤[]下标访问即可～(也可以⽤迭代器访问，下⾯会讲～)

	cout << "v.size() = " << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-06-18 18:08:52
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	//test01();

	test02();
	test03();

	return 0;
}
