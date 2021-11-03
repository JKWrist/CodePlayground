#include <iostream>
void test(const char * a,const char *b)
{
	printf("%s\n", a);
	printf("%s\n", b);
	char message[50];
	snprintf(message, sizeof(message), "a : %d, b : %d", a, b);
	printf("%s\n", message);
}

using namespace std;
int main(int argc, char *argv[]) 
{
	char * a = "asdaskdjl";
	char *b = NULL;
	test(a, b);
	
	char c[30] = {0};
	sprintf(c, "111%s222", b);
	printf("%s\n", c);
}