#include <stdio.h>
#include <string.h>

char *strlwr(char *s)
{
    if (NULL == s)
    {
        return NULL;
    }
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

    char src[40] = {0};
    char dest[12] = {0};
    strcpy(src, "ThisisBobasdasdkjaskdljalksdjl");

    strncpy(dest, src ,sizeof(dest) - 1);

    char dest2[12] = {0};
    strncpy(dest2, ",", sizeof(dest2) - 1);

    char dest3[12] = {0};
    strcpy(dest3, ",");
    strcat(dest3, ",");

    printf("最终的目标字符串： %s %s %s\n", dest, dest2, dest3);
    
    char str[] = "a04d6f21b1be97510844239354b03204fd6610d7eda9ed2e75423064afc355c1841c63232558ab6c6749201c89c565ac6807a181fcc086a5423e03824f3a76b3b538524d8bcb46a443f3ccdc5b07ae1385432701e6d686064d292878e65581c16300f8d822ec78cbe8fa808592121983d54870c418294636ec63f4a1a4033bcdddd9baf14b81a8183c164217dc2fb6745d64e7056d72c2bbccd5c4c5453a07022b7a258e1cf9ec15cd7b1f4344181f36ddb726ae3757c350825d9f20bf3ec2ec2094fa46f39d728c15d32f3111a16f57c59449506b7d0fcd469d96c608f5c6518812ffe460d5d38f0adf9286623e8fa27badd9e5392de897e4cc4c9ceb8847c3";
    printf("str = %s\n", str);

    // char str1[40] = "Js";
    // strcpy(src,strlwr(str1));
    // printf("str1： %s\n", str1);

    // int ret = strcmp(str1, "js");
    // printf("%d\n", ret);

    return 0;
}