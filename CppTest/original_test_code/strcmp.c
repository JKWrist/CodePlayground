#include <string.h>
#include <stdio.h>

int main(void)
{
    const char *string1 = "Hello World!1";
    const char *string2 = "Hello World1!";
    const char *string3 = "Hello World!2";
    int ret = strcmp(string1, string2);
    printf("ret %d\n", ret);

    ret = strcmp(string1, string3);
    printf("ret %d\n", ret);

    ret = strcmp(string2, string3);
    printf("ret %d\n", ret);

    ret = strcmp(string2, "Hello World1!");
    printf("ret %d\n", ret);

    return 0;
}