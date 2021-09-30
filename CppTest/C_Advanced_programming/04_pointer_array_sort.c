#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 18:12:24
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void selectSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[min] > arr[j])  //从小到大
            {
                min = j;
            }
        }

        if (i != min)
        {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}
/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 18:25:12
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 18:12:24
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    int arr[10] = {6, 7, 8, 3, 4, 1, 0, 6, 12, 9};
    selectSort(arr, sizeof(arr) / sizeof(int));
    printArray(arr, sizeof(arr) / sizeof(int));
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 19:04:30
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//void selectSort(char ** pArr, int num)
void selectSort2(char *array[], int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("%d\n", num);
        int min = i;
        for(int j = i + 1; j < num; j++)
        {
            if (strcmp(array[min], array[j]) > 0)
            {
                min = j;
            }
        }

        if(min != i)
        {
            printf("%s %s\n", array[i], array[min]);

            char *tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;

            printf("%s %s\n", array[i], array[min]);
        }
    }
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 18:25:12
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void printArray2(char * pArray[], int num)
{
    printf("-----------start---printArray2-------\n");
    printf("num %d\n", num);

    for (int i = 0; i < num; i++)
    {
        printf("%s\n", pArray[i]);
    }

    printf("-----------stop---printArray2-------\n");
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 18:12:24
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
    char *arr[] = {
        "asdasd",
        "aaaaa",
        "bbbbbb",
        "vvvvvvv",
        "cccccc",
        "fffffff",
        "hhhhhhh",
        "jjjjjj",
        "23452345",
        "opioipoip"
    };
    
    selectSort2(arr, sizeof(arr) / sizeof(char *));
    printf("sizeof(arr) %d\n", sizeof(arr));
    printf("sizeof(*arr) %d\n", sizeof(char *));

    printArray2(arr, sizeof(arr) / sizeof(char *));
}


/****************************************************************
 *  函数名称：main
 *  创建日期：2021-09-30 18:12:24
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //test01();
    test02();

    return 0;
}
