#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	string name;
	int age;
	float score;
} STU;

//模板是一种泛型技术，它能接受的类型是宽泛的、没有限制的，并且对这些类型使用的算法都是一样的（函数体或类体一样）。
//但是现在我们希望改变这种“游戏规则”，让模板能够针对某种具体的类型使用不同的算法（函数体或类体不同）
//这在 C++ 中是可以做到的，这种技术称为模板的显示具体化（Explicit Specialization）。

//函数模板
template<class T> const T& Max(const T& a, const T& b);

//函数模板的显示具体化（针对STU类型的显示具体化）
template<> const STU& Max<STU>(const STU& a, const STU& b);
//重载<<
ostream & operator<<(ostream &out, const STU &stu);
int main()
{
	int a = 10;
	int b = 20;
	cout << Max(a, b) << endl;
	
	STU stu1 = { "王明", 16, 95.5};
	STU stu2 = { "徐亮", 17, 90.0};
	cout << Max(stu1, stu2) << endl;
	
	return 0;
}

template<class T> const T& Max(const T& a, const T& b)
{
	return a > b ? a : b;
}

//Max<STU>中的STU表明了要将类型参数 T 具体化为 STU 类型，原来使用 T 的位置都应该使用 STU 替换，包括返回值类型、形参类型、局部变量的类型。

//Max<STU>中的STU是可选的，因为函数的形参已经表明，这是 STU 类型的一个具体化，编译器能够逆推出 T 的具体类型。简写后的函数声明为：
//template<> const STU& Max(const STU& a, const STU& b)
template<> const STU& Max<STU>(const STU& a, const STU& b)
{
	return a.score > b.score ? a : b;
}

ostream & operator<<(ostream &out, const STU &stu)
{
	out<<stu.name<<" , "<<stu.age <<" , "<<stu.score;
	return out;
}