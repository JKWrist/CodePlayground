//内联函数引出 宏缺陷

#include<iostream>
using namespace std;

//宏缺陷1 ： 必须要加括号保证运算完整
#define  MYADD(x,y)  ((x) +(y))
void test01()
{
	int a = 10;
	int b = 20;
	int ret = MYADD(a, b) * 20;
	cout << ret << endl;
}

//宏缺陷2：  即使加了括号，有些运算依然与预期不符

#define MYCOMPARE(a,b)  (((a) < (b)) ? (a) : (b))

//普通函数 不会出现与预期结果不符的问题
void myCompare(int a, int b)
{
	int ret = a < b ? a : b;
	cout << "ret = " << ret << endl;
}

void test02()
{
	int a = 10;
	int b = 20;

	myCompare(++a, b);

	//int ret = MYCOMPARE(++a, b); //预期是 11 结果变为12   (((++a) < (b)) ? (++a) : (b))

	//cout << "ret = " << ret << endl;

}


//内联函数
//函数的声明和实现必须同时加关键字 inline  才算内联函数
//内联函数 好处  ：解决宏缺陷，本身是一个函数，带来宏优势，以空间换时间，在适当的时候做展开
inline void func();
inline void func(){};
//类内部的成员函数 在函数前都隐式加了关键字 inline


int main(){

	test01();
	test02();
}