#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 0, int b = 0): m_a(a), m_b(b){}
private:
	int m_a;
	int m_b;
};

int main()
{
	//将 char* 转换为 float*
	char str[]="aaa";
	float *p1 = reinterpret_cast<float*>(str);
	cout << *p1 << endl;
	
	//将 int 转换为 int*
	int *p = reinterpret_cast<int*>(100);
	//将 A* 转换为 int*
	p = reinterpret_cast<int*>(new A(25, 96));
	cout << *p << endl;
	return 0;
}