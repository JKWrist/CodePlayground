#include <time.h>
#include <iostream>
using namespace std;
 
struct A 
{
    int a[10000];
};
void TestFunc1(A a) {}  // 传值
void TestFunc2(A& a) {}  // 传引用

A a;

A Fun3()
{
    return a;
}

A &Fun4() 
{
    return a;
}


void test1()
{
    A a;
    // 以值作为函数参数
    size_t begin1 = clock();
    for (size_t i = 0; i < 100000; ++i)
        TestFunc1(a);
    size_t end1 = clock();
    
    
    // 以引用作为函数参数
    size_t begin2 = clock();
    for (size_t i = 0; i < 100000; ++i)
        TestFunc2(a);
    size_t end2 = clock();

    // 分别计算两个函数运行结束后的时间
    cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
    cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
    
    
     // 以值作为函数返回值
    size_t begin3 = clock();
    for (size_t i = 0; i < 100000; ++i)
        Fun3();
    size_t end3 = clock();
    
    
    // 以引用作为函数返回值
    size_t begin4 = clock();
    for (size_t i = 0; i < 100000; ++i)
        Fun4();
    size_t end4 = clock();
    
    
    // 分别计算两个函数运行结束后的时间
    cout << "Fun3 time:" << end3 - begin3 << endl;
    cout << "Fun4 time:" << end4 - begin4 << endl;
}

int main()
{
    test1();
    return 0;
}