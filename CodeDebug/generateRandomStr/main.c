#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int __gen_random_string(char *random_str, int length)
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

int gen_random_string(char *random_str, int length)
{
    srand((unsigned)time(NULL));
    printf("time(NULL) %d\n", time(NULL));
    __gen_random_string(random_str, length);
}

//产生长度为length的随机字符串
char *genRandomString(int length)
{
    int flag, i;
    char *string;
    srand((unsigned)time(NULL));
    if ((string = (char *)malloc(length)) == NULL)
    {
        printf("Malloc failed!flag:14\n");
        return NULL;
    }

    for (i = 0; i < length - 1; i++)
    {
        flag = rand() % 3;
        switch (flag)
        {
        case 0:
            string[i] = 'A' + rand() % 26;
            break;
        case 1:
            string[i] = 'a' + rand() % 26;
            break;
        case 2:
            string[i] = '0' + rand() % 10;
            break;
        default:
            string[i] = 'x';
            break;
        }
    }
    string[length - 1] = '\0';
    return string;
}

void test_rand(void)
{
    unsigned long n;

    //srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++)
    {
        //如果在这里使用每次就都是一样的值了
        //srand((unsigned)time(NULL));
        n = rand();
        printf("%d\n", n);
    }
}

//error

//将数组转换为十六进制同值的字符串
//buflen为需要转换的字符长度，转成长度为两倍buflen的十六进制字符串
//out需要保证足够的大小(buflen * 2 + 1)来存放转换之后的数据
void array_to_hex_str_error(unsigned char *buf, unsigned int buflen, unsigned char *out)
{
    unsigned char strBuf[8] = {0};
    unsigned char i;
    for (i = 0; i < buflen; i++)
    {
        sprintf(strBuf, "%02x", buf[i]);
        strncat(out, strBuf, 2);  //这里只是一直往后拼接
    }
    out[buflen * 2] = 0;
}

//right

//将数组转换为十六进制同值的字符串
//buflen为需要转换的字符长度，转成长度为两倍buflen的十六进制字符串
//out需要保证足够的大小(buflen * 2 + 1)来存放转换之后的数据
void array_to_hex_str_right(unsigned char *buf, unsigned int buflen, unsigned char *out)
{
    unsigned char strBuf[128] = {0};
    unsigned char pTmpBuf[8] = {0};
    unsigned char i;
    for (i = 0; i < buflen; i++)
    {
        sprintf(pTmpBuf, "%02x", buf[i]);
        strncat(strBuf, pTmpBuf, 2);
    }
    strncpy(out, strBuf, buflen * 2); //关键步骤，把out的值全部覆盖
    out[buflen * 2] = 0;
}


int main()
{
    char str[65] = {0};
    char hex_str[65] = {0};
    for (int i = 0; i < 20; i++)
    {
        gen_random_string(str, 33);
        printf("1111 %s\n", str);

        sleep(1); //不休眠连续调用会导致字符串一样

        // array_to_hex_str_error(str, 32, hex_str);
        // printf("2222 %s\n", hex_str);

        array_to_hex_str_right(str, 32, hex_str);
        printf("3333 %s\n", hex_str);
    }

    // for (int i = 0; i < 20; i++)
    // {
    //     char *p = genRandomString(20);
    //     printf("333 %s\n", p);
    // }

    // test_rand();
}