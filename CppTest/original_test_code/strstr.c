#include<string.h>
#include<stdio.h>
int main()
{
	char * string1 = "needle in haystack";
	char * string2 = "hay";
	printf("%s\n", strstr(string1,string2));
}
