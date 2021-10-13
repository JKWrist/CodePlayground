#include<iostream>
using namespace std;

class A
{
public:
	void func();
public:
	int n;
};
void A::func(){ cout<<"c.biancheng.net"<<endl; }

class B: public A
{
public:
	int n;
	int m;
};

class C: public B
{
public:
	int n;
	int x;
};

int main()
{
	C obj;
	obj.n;
	obj.func();
	cout<<sizeof(C)<<endl;
	return 0;
}