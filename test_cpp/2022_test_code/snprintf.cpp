#include <stdio.h>
#include <stdlib.h>
int main()
{　
	char str[10]={0};
	int nLen=snprintf(str,sizeof(str),"123456789012345678");
	printf("str=%s\n",str);
	printf("nLen=%d\n",nLen);
	return 0;
}