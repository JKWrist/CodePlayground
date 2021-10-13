#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) 
{
	string a = "  aaaaa  ";
	char * p1 = "  aaaaa ";
	char p2[128] = {"  aaaaa  "};
	
	printf("%d\n", strcmp(p1, a.c_str()));
	printf("%d\n", strcmp(p2, a.c_str()));
	printf("%d\n", strcmp(p1, p2));
}