#include <stdio.h>
#include <string.h>

char *strlwr(char *s)
{
    char *str;
    str = s;
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str += 'a' - 'A';
        }
        str++;
    }
    return s;
}

int main()
{
    char str1[20] = "WwW.Bai!\"Du.Com";
    char *str2 = strlwr(str1);
    printf("str1 %s\nstr2 %s\n", str1, str2);
    return 0;
}