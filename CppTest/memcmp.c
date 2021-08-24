#include<string.h>
#include<stdio.h>
int main()
{
    char *s1 = "Hello,Programmers!";
    char *s2 = "Hello,Programmers!";
    int r;
    r = memcmp(s1,s2,strlen(s1));
    if(!r)
        printf("s1 and s2 are identical\n");/*s1等于s2*/
    else if(r<0)
        printf("s1 is less than s2\n");/*s1小于s2*/
    else
        printf("s1 is greater than s2\n");/*s1大于s2*/
    return 0;
}