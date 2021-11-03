#include "link.h"

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-02 17:45:55
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    struct LinkNode *pHeader = initLinkList();

    printf("遍历链表\n");
    foreach_LinkList(pHeader);

    //插入链表
    insert_Val(pHeader, 10);
    insert_Val(pHeader, 20);
    insert_Val(pHeader, 30);
    foreach_LinkList(pHeader);

    del_Val(pHeader, 20);
    foreach_LinkList(pHeader);

    return 0;
}
