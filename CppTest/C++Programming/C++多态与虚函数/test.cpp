#include <iostream>

using namespace std;

class ParentClass
{
public:
	ParentClass();    // 无参的构造函数
	ParentClass(int a);    // 带参数的构造函数
protected:
	int m_a;
};

ParentClass::ParentClass(int a)
	: m_a(a)
{
	// 这里可以作为测试并打印你的调用参数
	cout << "a: " << a << "\nm_a: " << m_a <<endl;
}


class ChildClass : public ParentClass
{
public:
	ChildClass();    // 这里随便你带不带参数了。没有参数的话，就直接给个默认是给父类或者调用父类无参数的构造函数。
}; 
 
ChildClass::ChildClass()
	: ParentClass(123)
{
}

int main(int argc, char *argv[]) 
{
	ChildClass a;
	return 0;
}