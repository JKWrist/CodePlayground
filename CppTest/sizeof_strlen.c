#include <stdio.h>
#include <string.h>
int main()
{
	
	char str[20000]="0123456789";
	int a =strlen(str); 
	printf("%d\n", a);
	//a=10; >>>> strlen 计算字符串的长度，以结束符 0x00 为字符串结束。
	int b =sizeof(str); 
	//而b=20000; >>>> sizeof 计算的则是分配的数组 str[20000] 所占的内存空间的大小，不受里面存储的内
	printf("%d\n", b);
	
	char* ss = "0123456789";
	printf("%d\n", sizeof(ss));
	//结果 4>>>>ss是指向字符串常量的字符指针，sizeof 获得的是一个指针的值所占的空间，是char*类型，所以是4
	printf("%d\n", sizeof(*ss));
	//结果 1>>>> *ss是第一个字符 其实就是获得了字符串的第一位'0' 所占的内存空间，是char类型的，占了 1 位
	printf("%d\n", strlen(ss));
	//>>>> 如果要获得这个字符串的长度，则一定要使用 strlen
	//sizeof返回对象所占用的字节大小. 正确
	//strlen返回字符个数. 正确
	
	return 0;
}