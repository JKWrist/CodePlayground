#include <iostream>

using namespace std;
int rev(int n)
{
	int new_n = 0;
	while(n)
	{
		new_n = new_n * 10 + n % 10;
		n = n / 10;
	}
	return new_n;
}
int main(int argc, char *argv[]) 
{
	for (int i = 1; i < 256; i++)
		if (i * i == rev(i * i))
			printf("%d\n", i);
}