/************************************************************************
> File Name: args_list.c
> Author:qusijun
> Mail: wiilen.lian@gmail.com 
> Created Time: 2013年11月15日 星期五 21时16分25秒
************************************************************************/

#include<stdio.h>

#include<stdarg.h>

void print_args(int args, ...)
{
    va_list ap;
    //在访问任何未命名的参数之前，必须用va_start宏初始化ap一次
    va_start(ap,args);
    
    printf("%d\n",args);
    printf("%d\n",va_arg(ap,int));
    printf("%s\n",va_arg(ap,char *));
    printf("%d\n",va_arg(ap,int));
    
    va_end(ap);

}


int main(void)
{
    int arg = 2;
    int args1 = 1;
    char *args2  = "lianwenlong";
    print_args(3,args1,args2,6);
    return 0;
}