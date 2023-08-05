// new 和 delete 的使用
#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person 构造函数调用" << endl;
	}
	Person(int a)
	{
		cout << "Person 有参构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person 析构函数调用" << endl;
	}
};

//malloc 和 new 区别
//malloc 和 free 属于库函数，new 和 delete 属于运算符
//malloc 不会调用构造函数，new会调用构造函数
//malloc返回void* C++下要强转，new 返回穿件的对象的指针
void test01()
{
	Person * p = new Person();
	delete p;
}

//注意事项，不要用void*去接收new出来的对象，利用void* 无法调用析构函数
void test02()
{
	void * p = new Person();
	delete p;
}

//利用new开辟数组
void test03()
{
	int * pInt = new int[10];
	delete [] pInt;

	double * pD = new double[20];
	delete [] pD;

	// //1、堆区开辟数组一定会调用默认构造函数
	// Person * pPerson1 = new Person[10];
	// //释放数组的时候，需要加[]
	// delete [] pPerson1;

	//2、堆区new对象 调用有参构造
	// Person * pPerson2 = new Person(1);
	// delete pPerson2;

	//3、栈上开辟数组，可不可以没有默认构造？  可以没有默认构造
	Person pArray[10] = {Person(10), Person(2), Person(1)};
}

int main()
{
	// test01();
	// test02();
	test03();
	return 0;
}