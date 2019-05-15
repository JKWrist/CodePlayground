#include <stdio.h>
#include <string.h>
int main()
{
	int sum = 0;
	char str[101];
	int out[5],count = 0;
	char a[][9] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	while(scanf("%s",str) != EOF);
	for(int i = 0; i < strlen(str); i++)
	{
		sum += str[i] - '0';
	}
//    printf("%d",sum);    
	
	while(sum != 0)
	{
		out[count] = sum % 10;
		sum /=10;
		count++;
	}
	for(int i = count-1; i > 0; i--)
		printf("%s ",a[out[i]]);
	printf("%s",a[out[0]]);
	
	return 0;
}