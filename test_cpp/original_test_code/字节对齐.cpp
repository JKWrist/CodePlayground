#include <iostream>
//#pragma pack(1)
//#pragma pack(4)
//#pragma pack(8)
using namespace std;

struct st01
{
	char c;
};

struct st02
{
	short c;
};

struct st03
{
	char c1;
	int a;
	char c2;
};

struct st04
{
	char c1;
	char c2;
	int a;
};

struct st05
{
	char arr[5];
	int a;
	short c2;
};

struct st06
{
	char arr[5];
	short c2;
	int a;
};


//成员变量以什么方式排列
//编译器对齐方式检查
int main(int argc, char *argv[]) 
{
	int i, j;
	printf("%ld, %ld \n", sizeof(st01), sizeof(st02));
	printf("%ld, %ld \n", sizeof(st03), sizeof(st04));
	printf("%ld, %ld \n", sizeof(st05), sizeof(st06));
	return 0;
}