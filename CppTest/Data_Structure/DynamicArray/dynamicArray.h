#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dynamicArray
{
    void ** pAddr;//维护在堆区创建的数组的指针
    
    int m_capacity;//数组容量

    int m_size; //数组大小
};

//初始化数组
struct dynamicArray * init_DynamicArray(int capacity);

//插入数组
void insert_DynamicArray(struct dynamicArray * array, int pos, void * data);

//遍历数组
void foreach_DynamicArray(struct dynamicArray* array, void(*myPrint)(void *));

//删除数组 按位置删除
void removeByPos_DynamicArray(struct dynamicArray* array, int pos);

//按值删除数据
void removeByValue_DynamicArray(struct dynamicArray *array, void * data, int(*myCompare)(void *, void *));

//销毁数组
void destory_DynamicArray(struct dynamicArray *array);