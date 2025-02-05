#include <iostream>
#include <string>
using namespace std;
class Demo
{
public:
	Demo(string s);
	~Demo();
private:
	string m_s;
};
Demo::Demo(string s)
: m_s(s)
{ 

}
Demo::~Demo()
{ 
	cout << m_s << endl; 
}
void func()
{
	//局部对象
	Demo obj1("1");
}
//全局对象
Demo obj2("2");

//析构函数在对象被销毁时调用，而对象的销毁时机与它所在的内存区域有关。不了解内存分区的读者请阅读《C语言内存精讲》专题。
//
//在所有函数之外创建的对象是全局对象，它和全局变量类似，位于内存分区中的全局数据区，程序在结束执行时会调用这些对象的析构函数。
//
//在函数内部创建的对象是局部对象，它和局部变量类似，位于栈区，函数执行结束时会调用这些对象的析构函数。
//
//new 创建的对象位于堆区，通过 delete 删除时才会调用析构函数；如果没有 delete，析构函数就不会被执行。
//
//下面的例子演示了析构函数的执行。

int main()
{
	//局部对象
	Demo obj3("3");
	//new创建的对象
	Demo * pobj4 = new Demo("4");
	delete pobj4;
	func();
	cout<<"main"<<endl;
	return 0;
}