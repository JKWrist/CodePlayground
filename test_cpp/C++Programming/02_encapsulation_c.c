#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person
{
	char name[64];
	int age;
};

void PersonEat(struct Person *p)
{
	printf("%s 在吃人饭\n", p->name);
}

struct Dog
{
	char name[64];
	int age;
};

void DogEat(struct Dog *dog)
{
	printf("%s 在吃狗粮\n", dog->name);
}

void test01()
{
	struct Person p1;
	strcpy(p1.name, "老王");
	p1.age = 30;
	PersonEat(&p1);

	struct Dog dog1;
	strcpy(dog1.name, "旺财");
	dog1.age = 10;
	DogEat(&dog1);

	DogEat(&p1);
}

int main()
{
	test01();

	return 0;
}