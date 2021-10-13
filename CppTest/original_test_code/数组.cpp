#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int buf[0xff];
	printf("%d\n", sizeof(buf));
	char a[10] = "asdasdasd";
	sprintf(a, sizeof(a), "%s", "21");
	printf("%s\n", a);
}