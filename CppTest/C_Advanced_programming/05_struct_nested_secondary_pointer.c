#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Teacher
{
    char *name;
    char **student;
} myTeacher;

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 10:29:54
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
myTeacher **allocateSpace(int iTeaNum, int iStNum)
{
    //pTeacher是一个指针， 指向了一个指针数组， 这个数组中存放了iTeaNum个教师指针
    //老师指针数组开辟内存
    myTeacher **pTeacher = (myTeacher **)malloc(sizeof(myTeacher *) * iTeaNum);
    for (int i = 0; i < iTeaNum; i++)
    {
        //每个老师分配内存
        pTeacher[i] = (myTeacher *)malloc(sizeof(myTeacher));

        //每个老师姓名分配内存
        pTeacher[i]->name = (char *)malloc(sizeof(char) * 64);
        sprintf(pTeacher[i]->name, "%s_%d", "Teacher", i);
        //printf("%s\n", pTeacher[i]->name);
        
        //学生数组分配内存

        //error
        //pTeacher[i]->student = (char **)malloc(sizeof(char *));
        //指针数组没有分配足够的大小导致出错

        //right
        pTeacher[i]->student = (char **)malloc(sizeof(char *) * iStNum);
        for (int j = 0; j < iStNum; j++)
        {
            //学生姓名分配内存
            //(pTeacher[i]->student)[j] = (char *)malloc(20);
            pTeacher[i]->student[j] = (char *)malloc(20);
            //sprintf((pTeacher[i]->student)[j], "%s_%d", "Student", j);
            sprintf(pTeacher[i]->student[j], "%s_%d", "Student", j);
            //printf("%s\n", (pTeacher[i]->student)[j]);
        }
    }

    return pTeacher;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 10:29:54
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void freeSpace(myTeacher **pTeacher, int iTeaNum, int iStuNum)
{
    if (pTeacher == NULL)
    {
        return;
    }

    for (int i = 0; i < iTeaNum; i++)
    {
        for (int j = 0; j < iStuNum; j++)
        {
            // if ((pTeacher[i]->student)[j])
            // {
            //     free((pTeacher[i]->student)[j]);
            //     (pTeacher[i]->student)[j] = NULL;
            // }
            if (pTeacher[i]->student[j])
            {
                free(pTeacher[i]->student[j]);
                pTeacher[i]->student[j] = NULL;
            }
        }

        if (pTeacher[i]->student)
        {
            free(pTeacher[i]->student);
            pTeacher[i]->student = NULL;
        }

        if (pTeacher[i]->name)
        {
            free(pTeacher[i]->name);
            pTeacher[i]->name = NULL;
        }

        if (pTeacher[i])
        {
            free(pTeacher[i]);
            pTeacher[i] = NULL;
        }
    }

    if (pTeacher)
    {
        free(pTeacher);
        pTeacher = NULL;
    }
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 11:08:37
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void printTeacher(myTeacher **pTeacher, int iTeaNum, int iStuNum)
{
    if (pTeacher == NULL)
    {
        return;
    }

    for (int i = 0; i < iTeaNum; i++)
    {
        printf("teacher name : %s\n", pTeacher[i]->name);
        printf("------------------student start------------------\n");
        for (int j = 0; j < iStuNum; j++)
        {
            //printf("%s\n", (pTeacher[i]->student)[j]);
            printf("%s\n", pTeacher[i]->student[j]);
        }
        printf("------------------student end------------------\n\n\n\n");
    }
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 10:45:41
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    myTeacher **pTeacher = allocateSpace(3, 2);
    printTeacher(pTeacher, 3, 2);
    freeSpace(pTeacher, 3, 2);
}

void test02()
{
    myTeacher **pTeacher = allocateSpace(4, 5);
    printTeacher(pTeacher, 4, 5);
    freeSpace(pTeacher, 4, 5);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-01 10:29:54
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    test01();


    //在分配更多学生时候发生崩溃的问题，暂未发现问题原因
    test02();
    //指针数组没有分配足够的大小导致出错，访问不改访问的内存越界引发的错误

    // a.out(78937,0x108165e00) malloc: *** error for object 0x5000000000000000: pointer being freed was not allocated
    // a.out(78937, 0x108165e00) malloc : ***set a breakpoint in malloc_error_break to debug
    //                                        Abort trap : 6 


    return 0;
}
