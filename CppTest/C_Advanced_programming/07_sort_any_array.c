#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 14:41:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void SortAllArray(void *pArray, int len, void (*pMysort)(void *, int))
{
    if (pArray == NULL)
    {
        return;
    }
    pMysort(pArray, len);

    //更好的方式是将公共用到的地方抽出来放到这里里面， 比如排序算法
}

void SortInt(void *array, int len)
{
    int *p = array;

    //使用选择排序
    int i = 0, j = 0;
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            printf("%d, %d\n", i, j);
            if (p[i] > p[j])
            {
                min = j;
            }
        }

        if (i != min)
        {
            int tmp = p[i];
            p[i] = p[min];
            p[min] = tmp;
        }
    }
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 14:41:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    int arr1[5] = {1, 2, 6, 7, 3};
    SortAllArray(arr1, sizeof(arr1) / sizeof(int), SortInt);

    for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
    {
        printf("%d\n", arr1[i]);
    }
    
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-03 14:41:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    test01();

    return 0;
}
