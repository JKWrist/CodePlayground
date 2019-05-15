#include <stdio.h>
#define <stdlib.h>
#define nothing_go -8
#define nothing_come 8
#define wolf_go -12
#define wolf_come 12
#define vegetable_go -9
#define vegetable_come 9
#define sheep_go -10
#define sheep_come 10

typedef struct Result
{
	int r[100];
	int length;	
}Result;

Result Result[10];
int re_num = 0;
int queue[100], length = 0;

int judge(int a)
{
	int i;
	if(a>15||a<0)
		return 0;
	if(a == 3||a==6||a==7||a==8||a==9||a==12)
		return 0;
	for (i = 0; i < length; i++)
	
}
Results Result;

int main(int argc, char *argv[]) 
{
	
}