#include<stdio.h>
#include<stdlib.h>
 
struct list_head {
    struct list_head *next, *prev;
};
 
#define INIT_LIST_HEAD(ptr) do {  (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
 
static inline void __list_add(struct list_head *add,
        struct list_head *prev,
        struct list_head *next)
{
    next->prev = add;
    add->next = next;
    add->prev = prev;
    prev->next = add;
}

//每次添加节点都是头结点之前，由于是循环链表，就是说添加到链表尾部
static inline void list_add_tail(struct list_head *add, struct list_head *head)
{
    __list_add(add, head->prev, head);
}
 
#define offsetof(struct_t,member) ((size_t)(char *)&((struct_t *)0)->member)
 
#define container_of(ptr, type, member) ({                  \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) );})
 
#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)
 
#define list_for_each_entry(pos, head, member)                          \
    for (pos = list_entry((head)->next, typeof((*pos)), member);        \
         &pos->member != (head);                                        \
         pos = list_entry(pos->member.next, typeof((*pos)), member))
 
struct node
{
    int val;
    struct list_head my_list;
};
 
int main()                                                                                                                                                                                                  
{
    struct list_head head;
    struct node a,b,c,*pnode;
 
    a.val = 1;
    b.val = 2;
    c.val = 3;
 
    INIT_LIST_HEAD(&head);            //初始化链表头
    list_add_tail(&a.my_list,&head);     //添加节点
    list_add_tail(&b.my_list,&head);
    list_add_tail(&c.my_list,&head);
 
    printf("*******************************************\n");
 
    list_for_each_entry(pnode,&head,my_list)//遍历链表，打印结果
    {
        printf("val = %d\n",pnode->val);
    }//print 1 2 3 
 
    printf("*******************************************\n");
    struct node d,e;
    d.val = 4;
    e.val = 5;
    list_add_tail(&d.my_list,&head);
    list_add_tail(&e.my_list,&head);
 
    list_for_each_entry(pnode,&head,my_list)
    {
        printf("val = %d\n",pnode->val);
    }//print 1 2 3 4 5
 
    printf("*******************************************\n");
 
    return 0;
}