#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * func()
{
    char * p = malloc(10);
    memset(p, 0, 10);
    strcpy(p, "Hello");
    return p;
}

//


/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 16:19:45
*/
int main()
{
    char *p = func();
    printf("%s\n", p);
    return 0;
}
