// //递增运算符重载

// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// using namespace std;

// class MyInter
// {
// 	friend ostream & operator<<(ostream & cout, MyInter & myInt);
// public:
// 	MyInter()
// 	{
// 		m_Num = 0;
// 	}
// 	//前置++ 重载
// 	MyInter & operator++()
// 	{
// 		this->m_Num++;
// 		return *this;
// 	}

// 	//后置++ 重载
// 	MyInter operator++(int)
// 	{
// 		//先记录初始状态
// 		MyInter temp = *this;
// 		this->m_Num++;
// 		return temp;
// 	}
// private:
// 	int m_Num;
// };

// ostream & operator<<(ostream & cout, MyInter & myInt)
// {
// 	cout << myInt.m_Num << endl;
// 	return cout;
// }

// void test01()
// {
// 	MyInter myInt;
// 	cout << ++(++myInt);
// 	cout << myInt;
// }

// void test02()
// {
// 	MyInter myInt;
// 	cout << myInt++;
// 	cout << myInt;
// }

// /****************************************************************
//  *  函数名称：main
//  *  创建日期：2022-04-19 20:13:27
//  *  作者：xujunze
//  *  输入参数：无
//  *  输出参数：无
//  *  返回值：无
// ******************************************************************/
// int main()
// {
// 	//test01();
// 	test02();
// 	return 0;
// }


#include <iostream>
using namespace std;
 
class Point
{
	friend ostream& operator<<(ostream& cout, Point &p);
public:
    Point(float xx, float yy) :x(xx), y(yy) {}

	//重载前置++
    Point &operator++()
    {
        x = x + 1;
        y = y + 1;
		cout << "前置++" << endl;
        return *this;  //返回当前对象
    }

	//重载后置++,使用一个占位符与前置++进行一个区分
    Point operator++(int)
    {
        Point c = *this;  //将加之前的对象保存在临时变量里
        x = x + 1;
        y = y + 1;
		cout << "后置++" << endl;
        return c; //返回加之前的对象
    }

private:
    float x, y;
};

ostream& operator<<(ostream& cout, Point &p)
{
	cout << "[" << "p.x " << p.x << ", p.y " << p.y << "]"<< endl;
	return cout;
}
 
int main()
{   
    Point a(1, 2);
    Point b(3, 4);
    
    b = ++a;
	cout << a;
    cout << b;
	

    cout << endl << "---------------------" << endl;
 
    b = a++;
    cout << b;
	cout << a;

    return 0;
}   