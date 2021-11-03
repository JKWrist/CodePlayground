#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	char * pHeadBuffer = NULL;
	for(int i = 5; i < 2000; i++)
	{
		pHeadBuffer = new char[i + 1];
		printf("length = %d \n", i + 1);
		memset(pHeadBuffer, 0, i + 1);
	}
	
}