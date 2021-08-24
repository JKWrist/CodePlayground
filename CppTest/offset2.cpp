//#define OFFSETOF(type, member) ((int64_t)&((type*)0)->member)//64位主机
//#define OFFSETOF(type, member) ((int32_t)&((type*)0)->member)//32位主机


//#define offsetoff(TYPE,MEMBER)  ( (size_t)( &( ( (TYPE*)0 )->MEMBER ) ) )
//实现解析
//(TYPE*)0是一个空指针，如果使用空指针访问成员肯定造成段错误，但是前面的”&”这个符号，表示我们仅仅取MEMBER字段的地址，而不是引用该字段内容，因此不会造成段错误。
//
//另外，结构体中的字段在内存中分配的地址是连续的，当我们去访问某个字段时，例如，&( ( (TYPE*)0 )->MEMBER ) )，会先取得该结构体类型TYPE的地址，然后再计算MEMBER字段的offset；最后，将TYPE的地址加上MEMBER的offset，得到MBMBER字段真正的地址，而这个动作是由编译器帮我们完成的。
//
//比如：使用&(ptr->member)获取member的地址，假设ptr地址为100，那么member的地址就是100+offset，如果ptr地址为0，那么得到的结果就是member在type中的offset。

#include <iostream>
#include <stdint.h>
using namespace std;

#define OFFSET1(type, member) ((size_t)&((type*)0)->member)

typedef struct A
{
    int a;
    char b;
    short c;
}A;

int main()
{
    /*int a = 10;
    int *p = &a;
    cout << sizeof(p) <<endl;*/
    
    cout << OFFSET1(A, a) <<endl;
    cout << OFFSET1(A, b) <<endl;
    cout << OFFSET1(A, c) <<endl;
    cout << sizeof(A) <<endl;
    return 0;
}