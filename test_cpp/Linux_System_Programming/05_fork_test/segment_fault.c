#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// 1>. 访问了非法内存
// 2>. 访问了不可写的区域进行写操作
// 3>. 栈空间溢出
// char* p = “hello，world”        
// p【0】=‘a’；


/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-21 15:41:07
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    char * p = "hello world\n";
    printf("%s\n", p);
    p[1] = 'a';
    return 0;
}
