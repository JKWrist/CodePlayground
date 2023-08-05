
#pragma pack(1)

#include <stdio.h>

typedef struct _STUDENT
{
	int a;   //0 ~ 3
	char b;   //4
	double c;  //5 ~ 13  double放到8的整数倍上
	float d;	//16 ~ 20  float放到4的整数倍上
} Student;   //24

typedef struct _STUDENT2
{
	char a;
	Student b;
	double c;
} Student2;  //40

void test01()
{
	printf("sizeof Student:%d\n",sizeof(Student));
	printf("sizeof Student2:%d\n",sizeof(Student2));
	printf("---------------------------\n");
}

int main()
{
	test01();
	
	return 0;
}