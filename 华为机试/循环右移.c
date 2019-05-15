#include <stdio.h>
#include <string.h>
#define Maxsize 20
void LoopMove(char *str, int steps)
{
	int len = strlen(str);
	char tmp[Maxsize];
	strcpy(tmp, str+len-steps);
	strcpy(tmp+steps, str);
	*(tmp + len) = '\0';
	strcpy(str, tmp);
}
int main(int argc, char *argv[]) 
{
	char str[] = "abcdefghigh";
	LoopMove(str, 2);
	printf("%s", str);
}