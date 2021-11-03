#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//sprintf
void test01()
{
    char buffer[1024] = {0};

    //格式化字符串
    sprintf(buffer, "asdkask %s ldjal", "bendan");
    printf("%s\n", buffer);

    memset(buffer, 0, 1024);
    sprintf(buffer, "今年我多少岁了 %d", 103);
    printf("%s\n", buffer);

    //拼接字符串
    char str1[] = "hello";
    char str2[] = "world";
    memset(buffer, 0, 1024);
    sprintf(buffer, "%s %s", str1, str2);
    printf("%s\n", buffer);

    //数字转换字符串
    int num = 65535;
    memset(buffer, 0, 1024);
    sprintf(buffer, "%d", num);
    printf("%s123\n", buffer);

    //设置宽度， 右对齐
    memset(buffer, 0, 1024);
    sprintf(buffer, "%8d", num);
    printf("%s123\n", buffer);

    //设置宽度，左对齐
    memset(buffer, 0, 1024);
    sprintf(buffer, "%-8d", num);
    printf("%s123\n", buffer);

    //转成16进制字符串
    memset(buffer, 0, 1024);
    sprintf(buffer, "0x%x", num);
    printf("%s\n", buffer);

    //转成8进制字符串
    memset(buffer, 0, 1024);
    sprintf(buffer, "0%o", num);
    printf("%s\n", buffer);
}

//

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-07 16:44:10
*/
int main()
{
    test01();

    return 0;
}
