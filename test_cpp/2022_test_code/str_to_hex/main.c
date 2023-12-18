
//目标：将随机字符串转换成16进制字符串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int __gen_random_string(char *random_str, int length)
{
    int flag, i;

    if (NULL == random_str)
    {
        printf("random_str is NULL\n");
        return -1;
    }

    if (length < 1)
    {
        printf("length < 1\n");
        return -1;
    }

    for (i = 0; i < length - 1; i++)
    {
        flag = rand() % 5;
        switch (flag)
        {
        case 0:
        case 1:
            random_str[i] = 'A' + rand() % 26;
            break;
        case 2:
        case 3:
            random_str[i] = 'a' + rand() % 26;
            break;
        case 4:
            random_str[i] = '0' + rand() % 10;
            break;
        default:
            random_str[i] = 'x';
            break;
        }
    }

    random_str[length - 1] = '\0';

    return 0;
}

//将数组转换为十六进制同值的字符串
//buflen为需要转换的字符长度，转成长度为两倍buflen的十六进制字符串
//out需要保证足够的大小来存放转换之后的数据
void array_to_hex_str(unsigned char *buf, unsigned int buflen, unsigned char *out)
{
    unsigned char strBuf[128] = {0};
    unsigned char pTmpBuf[32];
    unsigned char i;
    for (i = 0; i < buflen; i++)
    {
        sprintf(pTmpBuf, "%02x", buf[i]);
        printf("pTmpBuf %s\n", pTmpBuf);
        strncat(strBuf, pTmpBuf, 2);
    }
    strncpy(out, strBuf, buflen * 2);
    out[buflen * 2] = 0;
}

int main()
{
    char str[65] = {0};
    __gen_random_string(str, 65);

    char ptr[65];
    array_to_hex_str(str, 32, ptr);
    printf("结果：%s\n", ptr);
}