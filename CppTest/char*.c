#include <stdio.h>
#include <string.h>
void fun(char * p)
{
	if(p != NULL && p[0] != '\0')
	{
		printf("%lu, %s\n", strlen(p), p);
	}
}
int main(int argc, char *argv[]) 
{
	char * msg = "abcdefghighlmn";
	fun(msg);
	
	char * msg1 = "aaa";
	fun(msg1);
		
	char * msg2 = "";
	fun(msg2);
	
	char * msg3 = NULL;
	fun(msg3);
			
	char str[20]={NULL};
	strcpy(str,"1234567890");
	
	fun(str);
}