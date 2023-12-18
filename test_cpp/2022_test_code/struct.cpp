#include <iostream>

using namespace std;
struct A
{
	char a;
	long b;
	char c;
	double d;
};
struct B
{
	char a;
	char c;
	long b;
	double d;
};

int main(int argc, char *argv[]) 
{
	
	printf("%ld, %ld, %ld, %ld\n", sizeof(int), sizeof(long), sizeof(struct A), sizeof(struct B));
}