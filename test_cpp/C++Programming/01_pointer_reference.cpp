//指针引用

#include <iostream>
using namespace std;

struct Person
{
	int age;
};

void allocateSpace(Person **p)
{
	//p 指向指针的指针，*p 是指针，指向Person本体， **p Person本体
	*p = (Person *) malloc(sizeof(Person));
	(*p)->age = 10;
}

void test01()
{
	Person * p = NULL;
	allocateSpace(&p);
	cout << "p->age " << p->age << endl;
}

void allocateSpace2(Person * &pp) //Person * &pp = p
{
	pp = (Person *)malloc(sizeof(Person));
	pp->age =  20;
}

void test02()
{
	Person * p = NULL;
	allocateSpace2(p);
	cout << "p->age " << p->age << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}