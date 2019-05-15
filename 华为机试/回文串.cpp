#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 256;

int main(int argc, char *argv[]) 
{
	int num = 0;
	char ans[90][90];
	while(scanf("%s", ans[num]) != EOF)
		num++;
	for (int i = num -  1; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if (i > 0)
			printf(" ");
	}
}