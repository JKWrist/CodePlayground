#include <stdio.h>
#include <string.h>

int reverse(char *pstr)
{
    if(pstr == NULL)
    {
        return -1;
    }

    char ctmp;
    char *pstart = pstr;
    char *pend = pstart + strlen(pstart) - 1;
    while(pstart < pend)
    {
        ctmp = *pstart;
        *pstart++ = *pend;
        *pend-- = ctmp;
    }

    return 0;
}

int str_abcba(const char *pstr)
{
    if(NULL == pstr)
    {
        return -1;
    }
    char * pstart = pstr;
    char * pend = pstr + strlen(pstr) - 1;
    while(pstart++ < pend--)
    {
        if(*pstart != *pend)
        {
            return -1;
        }
    }
    return 0;
}

int sub_str_num(const char *pstr, const char *psubstr)
{
    if (NULL == pstr || psubstr == NULL)
    {
        return -1;
    }

    int num = 0;
    char * p = strstr(pstr, psubstr);
    while(p)
    {
        num++;
        p += strlen(psubstr);
        p = strstr(p, psubstr);
    }
    
    return num;
}

int main()
{
    char str1[] = "abcdefg";
    char str2[] = "abcdcba";
    char str3[] = "helloNl1lo+llo";
    char str4[] = "llo";

    int ret = 0;
    printf("reverse original %s\n", str1);
    ret = reverse(str1);
    printf("reverse result %s %d \n", str1, ret);

    printf("abcba original %s\n", str2);
    ret = str_abcba(str2);
    printf("abcba result %d\n", ret);

    printf("sub_str_num original %s %s\n", str3, str4);
    ret = sub_str_num(str3, str4);
    printf("sub_str_num result %d\n", ret);

    return 0;
}