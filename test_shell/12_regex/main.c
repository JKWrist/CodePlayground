#include <sys/types.h>
#include <regex.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    if (argc != 3)
    {
        printf("Usage: %s RegexString Text\n", argv[0]);
        return 1;
    }
    const char * pregexstr = argv[1]; //正则的输入
    const char * ptext = argv[2];     //要匹配的文本
    regex_t oregex;                   //声明正则结构体
    int nerrcode = 0;
    char szerrmsg[1024] = {0};
    size_t unerrmsglen = 0;

    //编译正则表达式
    if ((nerrcode = regcomp(&oregex, pregexstr, REG_EXTENDED|REG_NOSUB)) == 0)
    {
        //如果编译通过，就用正则来匹对文本
        if ((nerrcode = regexec(&oregex, ptext, 0, NULL, 0)) == 0)
        {
            //匹对成功
            printf("%s matches %s\n", ptext, pregexstr);
            regfree(&oregex);
            return 0;
        }
    }

    //出错的情况下错误输出
    unerrmsglen = regerror(nerrcode, &oregex, szerrmsg, sizeof(szerrmsg));
    unerrmsglen = unerrmsglen < sizeof(szerrmsg) ? unerrmsglen : sizeof(szerrmsg) - 1;
    szerrmsg[unerrmsglen] = '\0';
    printf("ErrMsg: %s\n", szerrmsg);
    regfree(&oregex);
    return 0;
}