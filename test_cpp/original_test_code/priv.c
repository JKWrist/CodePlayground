#include <stdio.h>

int main()
{
    char pstr[] = "abcdefghigk"; 
    char * p = pstr;

    while(*p)
    {
        printf("%c",*++p);
    }
    printf(" \n");
    return 0;
}