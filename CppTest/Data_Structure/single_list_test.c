//分析宏定义中真正的数据结构，头结点与结点结构体

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	SLIST_HEAD(name, type)                          \
struct name {                                           \
    struct type *slh_first;	/* first element */         \
}

// 用于定义一个（用户）结构体的成员变量，该成员变量只包含一个指向type类型的指针sle_next；
#define	SLIST_ENTRY(type)                               \
struct {                                                \
    struct type *sle_next;  /* next element */          \
}

// 用于获取单向链表的第一个元素；
#define SLIST_FIRST(head)   ((head)->slh_first)

// 用于初始化SLIST_HEAD定义的头指针变量；
#define SLIST_INIT(head) do {                           \
        SLIST_FIRST((head)) = NULL;                     \
} while (0)


struct SLIST_ITEM {
	int value;
	SLIST_ENTRY(SLIST_ITEM) entry;
};
/*
struct SLIST_ITEM {
	int value;
	struct
	{
    	struct SLIST_ITEM *sle_next;
	}entry;
};
*/

static SLIST_HEAD(,SLIST_ITEM) slist_head;
/*
struct {                      \
    struct SLIST_ITEM *slh_first;   \
}slist_head;
*/


/****************************************************************
 *  函数名称：main
 *  创建日期：2022-06-08 09:26:28
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	SLIST_INIT(&slist_head);
	printf("%d\n", sizeof(slist_head));


	struct SLIST_ITEM item;
	printf("%d\n", sizeof(item));

	item.entry.sle_next = NULL;
	return 0;
}
