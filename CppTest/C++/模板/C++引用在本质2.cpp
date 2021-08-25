#include <iostream>
#include <iomanip>
using namespace std;
int num = 99;

class A
{
public:
	A();
private:
	int n;
	int &r;
};

A::A()
: n(0)
, r(num)
{
	
}

int main ()
{
	A *a = new A();
	cout << sizeof(A) << endl;  //输出A类型的大小
	
	//hex表示以十六进制输出，showbase表示添加十六进制前缀0x
	cout << "1111: " << hex << showbase << *((int*)a + 1) << endl;  //输出r本身的内容
	cout << &num << endl;  //输出num变量的地址
	return 0;
}