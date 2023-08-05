/* strstr example */
#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] ="This is a simple string";
	char * pch;
	pch = strstr (str,"simple");
	puts (pch);
	
	strncpy (pch,"sample",6);
	puts (str);
	
	
	char haystack[20] = "RUNOOB";
	char needle[10] = "ROOB";
	char *ret;
 
	ret = strstr(haystack, needle);
 
	printf("子字符串是： %s\n", ret);
	
	return(0);
	
	return 0;
}