#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member)                                        \
  ({                                                                           \
    const typeof(((type *)0)->member) *__mptr = (ptr);                         \
    (type *)((char *)__mptr - offsetof(type, member));                         \
  })

/****************************************************************
 *  函数名称：container_of的使用
 *  创建日期：2022-01-27 17:33:49
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
 ******************************************************************/
struct student
{
	int age;
	char name[20];
	char sex;
};

void test01()
{
	struct student stu = {18, "xiaohong", 'w'};
	struct student *p;
	p = container_of(&stu.name, struct student, name);
	printf("%d %s %c\n", p->age, p->name, p->sex);
	printf("---------------------------\n");
}

/****************************************************************
 *  函数名称：结构体存储
 *  创建日期：2022-01-27 17:39:49
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
	struct student stu = {18, "xiaohong", 'w'};
	printf("%x\n", &stu);
	printf("%x\n", &stu.age);
	printf("%x\n", &stu.name);
	printf("%x\n", &stu.sex);
	printf("---------------------------\n");
}

int main()
{
	test01();
}