
/****************************************************************
 *  函数名称：声明
 *  创建日期：2022-06-08 08:47:56
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/

// 用于定义一个单向链表数据结构的头指针，该结构体只有一个指针成员slh_first
// 指向第一个type类型的数据结构；
#define	SLIST_HEAD(name, type)                          \
struct name {                                           \
    struct type *slh_first;	/* first element */         \
}

// 用于在定义时初始化SLIST_HEAD定义的数据结构的头指针；
#define	SLIST_HEAD_INITIALIZER(head)                    \
    { NULL }

// 用于定义一个（用户）结构体的成员变量，该成员变量只包含一个指向type类型的指针sle_next；
#define	SLIST_ENTRY(type)                               \
struct {                                                \
    struct type *sle_next;  /* next element */          \
}

/****************************************************************
 *  函数名称：函数
 *  创建日期：2022-06-08 08:48:15
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/

// 用于判断单向链表是否为空：空则返回true，否则返回false；
#define SLIST_EMPTY(head)   ((head)->slh_first == NULL)

// 用于获取单向链表的第一个元素；
#define SLIST_FIRST(head)   ((head)->slh_first)

// 用于获取elm元素的下一个元素，field是前面用SLIST_ENTRY定义的成员变量名；
#define SLIST_NEXT(elm, field)	((elm)->field.sle_next)

// 用于初始化SLIST_HEAD定义的头指针变量；
#define SLIST_INIT(head) do {                           \
        SLIST_FIRST((head)) = NULL;                     \
} while (0)

// 用于遍历单向链表，var是临时变量，head是链表头指针（SLIST_HEAD定义的变量），
// field是SLIST_ENTRY定义的成员变量名；
#define SLIST_FOREACH(var, head, field)                 \
    for ((var) = SLIST_FIRST((head));                   \
        (var);                                          \
        (var) = SLIST_NEXT((var), field))

// 用于将元素elm插入到当前链表元素slistelm的后面；
#define SLIST_INSERT_AFTER(slistelm, elm, field) do {           \
    SLIST_NEXT((elm), field) = SLIST_NEXT((slistelm), field);   \
    SLIST_NEXT((slistelm), field) = (elm);                      \
} while (0)

// 用于将元素elm插入到当前链表head的头部；head是SLIST_HEAD定义的链表头指针；
#define SLIST_INSERT_HEAD(head, elm, field) do {            \
    SLIST_NEXT((elm), field) = SLIST_FIRST((head));         \
    SLIST_FIRST((head)) = (elm);                            \
} while (0)

// 用于从head链表中删除elm元素；注意首先判断elm元素是否在head链表中，否则会崩溃；
#define SLIST_REMOVE(head, elm, type, field) do {           \
    if (SLIST_FIRST((head)) == (elm)) {                     \
        SLIST_REMOVE_HEAD((head), field);                   \
    }                                                       \
    else {                                                  \
        struct type *curelm = SLIST_FIRST((head));          \
        while (SLIST_NEXT(curelm, field) != (elm))          \
            curelm = SLIST_NEXT(curelm, field);             \
        SLIST_NEXT(curelm, field) =                         \
            SLIST_NEXT(SLIST_NEXT(curelm, field), field);   \
    }                                                       \
} while (0)

// 用于删除第一个元素；注意删除时判断head是否为空，否则会崩溃;
#define SLIST_REMOVE_HEAD(head, field) do {                         \
    SLIST_FIRST((head)) = SLIST_NEXT(SLIST_FIRST((head)), field);   \
} while (0)


#include <stdio.h>
#include <stdlib.h>
//#include <sys/queue.h>

struct SLIST_ITEM {
	int value;
	SLIST_ENTRY(SLIST_ITEM) entry;
};

static SLIST_HEAD(,SLIST_ITEM) slist_head;

int main(int argc, char *argv[])
{
	int i = 0;
	struct SLIST_ITEM *item;
	struct SLIST_ITEM *tmp_item;

	SLIST_INIT(&slist_head);

	if (SLIST_EMPTY(&slist_head)) {
		printf("single list is empty\n");
    }

	for( i = 0; i < 10; i ++)
	{
		item = (struct SLIST_ITEM *)malloc(sizeof(struct SLIST_ITEM));
		item->value = i;
        // 头部插入：即9,8,7,6,5,4,3,2,1,0
        // 用于将元素item插入到当前链表slist_head的头部
		SLIST_INSERT_HEAD(&slist_head, item, entry);
	}
    
    for( i = 0; i < 10; i ++) {
		tmp_item = (struct SLIST_ITEM *)malloc(sizeof(struct SLIST_ITEM));
		tmp_item->value = i + 10;
        // 尾部插入：即9,10,11,12...19,8,7,..1,0
        // 用于将元素tmp_item插入到item的后面
		SLIST_INSERT_AFTER(item, tmp_item, entry);
        // 置换位置,让下一个元素在当前元素之后
        item = tmp_item;
	}
    
	printf("after insert 10 item to single list:\n");
	SLIST_FOREACH(item, &slist_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", item, item->value);

	SLIST_FOREACH(tmp_item, &slist_head, entry) {
	    // 将删除1.3.5.7.9...
	    // 用于从slist_head链表中删除tmp_item元素
		if(tmp_item->value % 2 != 0) {
            printf("Remove item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);
			SLIST_REMOVE(&slist_head, tmp_item, SLIST_ITEM, entry);
            free(tmp_item);
		}
	}

	printf("after delete items from single list, the rest:\n");
	SLIST_FOREACH(item, &slist_head, entry)
        printf("Has Item pointer = %p, item value = %d\n", item, item->value);

    SLIST_FOREACH(tmp_item, &slist_head, entry) {
        // 删除slist_head链表中头部元素
        printf("Remove head item pointer = %p, item value = %d\n", tmp_item, tmp_item->value);
        SLIST_REMOVE_HEAD(&slist_head, entry);
        free(tmp_item);
    }
    
    if (SLIST_EMPTY(&slist_head)) {
		printf("single list is empty!!!\n");
    }

	return 0;
}