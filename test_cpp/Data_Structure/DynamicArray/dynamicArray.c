#include "dynamicArray.h"

/****************************************************************
 *  函数名称：init_DynamicArray
 *  创建日期：2021-10-08 17:19:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//初始化数组
struct dynamicArray *init_DynamicArray(int capacity) 
{
    if(capacity <= 0)
    {
        return NULL;
    }
    //给数组分配空间
    struct dynamicArray *array = (struct dynamicArray *)malloc(sizeof(struct dynamicArray));
    if(NULL == array)
    {
        return NULL;
    }

    //数组初始化
    array->pAddr = malloc(sizeof(void *) * capacity);
    array->m_capacity = capacity;
    array->m_size = 0;

    return array;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-08 17:57:32
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//插入数组
void insert_DynamicArray(struct dynamicArray *array, int pos, void *data) 
{
    if(NULL == array || data == NULL)
    {
        return;
    }

    //无效位置，尾插
    if(pos < 0 || pos > array->m_size)
    {
        pos = array->m_size;
    }

    //判断数组是否满了， 如果满了则动态扩展
    if(array->m_size == array->m_capacity)
    {
        //1、计算空间大小
        int newCapacity = array->m_capacity * 2;

        //2、创建新空间
        void **newSpace = malloc(sizeof(void *) * newCapacity);

        //3、将原有数据拷贝到新空间下
        memcpy(newSpace, array->pAddr, sizeof(void *) * array->m_capacity);

        //4、释放原有内存空间
        free(array->pAddr);

        //5、更新新空间指向
        array->pAddr = newSpace;

        //6、更新新容量
        array->m_capacity = newCapacity;
    }

    //插入新元素

    //移动元素， 插入新元素
    for (int i = array->m_size - 1; i >= pos; i--)
    {
        //数据向后移动
        array->pAddr[i+1] = array->pAddr[i];
    }

    //将新元素插到指定位置上
    array->pAddr[pos] = data;

    //更新大小
    array->m_size++;
}

/****************************************************************
 *  函数名称：foreach_DynamicArray
 *  创建日期：2021-10-08 17:57:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//遍历数组
void foreach_DynamicArray(struct dynamicArray *array, void (*myPrint)(void *)) 
{
    if (NULL == array || NULL == myPrint)
    {
        return;
    }
    
    for (int i = 0; i < array->m_size; i++)
    {
        myPrint(array->pAddr[i]);
    }
    
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-08 17:57:39
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//删除数组 按位置删除
void removeByPos_DynamicArray(struct dynamicArray *array, int pos) 
{
    if (NULL == array)
    {
        return;
    }

    if (pos < 0 || pos > array->m_size - 1)
    {
         return;
    }

    //数据前移
    for (int i = pos; i < array->m_size - 1; i++)
    {
        array->pAddr[i] = array->pAddr[i + 1];
    }

    array->m_size--;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-08 18:13:02
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//按值删除数据
void removeByValue_DynamicArray(struct dynamicArray *array, void *data, int (*myCompare)(void *, void *)) 
{
    if(NULL == array || NULL == data)
    {
        return;
    }

    for (int i = 0; i < array->m_size; i++)
    {
        if (myCompare(array->pAddr[i], data))
        {
            removeByPos_DynamicArray(array, i);
            break;
        }
        
    }
}

/****************************************************************
 *  函数名称：destory_DynamicArray
 *  创建日期：2021-10-08 18:14:28
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//销毁数组
void destory_DynamicArray(struct dynamicArray *array) 
{
    if (NULL == array)
    {
        return;
    }
    
    if(array->pAddr)
    {
        free(array->pAddr);
        array->pAddr = NULL;
    }

    free(array);
    array = NULL;  //此处赋值NULL在此函数中防止野指针出现，但是如果要修改array要传高一级的指针来进行修改
}