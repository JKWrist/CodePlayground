#include <string.h>
#include <stdio.h>
int main()
{
	char str1[] = "asdas.hdbjh.absde";
	char *str2 = "asdas.hdbjh.absde";
	char str3[] = "asd,as.hdbj,h.ab,sde";
	
	char *p = strtok(str1, ".");
	
	for (int i = 0; i < 17; i++)
	{
		//printf("%c %d %c %d\n", str1[i], str1[i], p[i], p[i]);
	}
	//注意点一 str2 在这里是常量。而strtok会修改字符串的内容，此处第一个参数不能传递常量
	//strtok(str2, ".");  
	
	//注意二 strtok 在往后获取的时候，第一个参数传递NULL  原理：其内部有一个静态变量记录后面指针的位置，所以也不是线程安全函数
	//strtok_r是linux下线程安全函数
	while(p != NULL)
	{
		printf("%s\n", p);
		p = strtok(NULL, ".");
	}
	
	//注意三 strtok 第二个参数可以传递多个字符，每一个字符都是分隔符
	char *p1 = strtok(str3, ".,");
	while(p1 != NULL)
	{
		printf("%s\n", p1);
		p1 = strtok(NULL, ".,");
	}
	
	return 0;
}