#include <stdio.h>
#include <string.h>

#define N 100

// 题目：输入一串字符串，输出其中有多少个单词。例如：i am a boy，输出四个。

// 思考：问题的关键在于空格的判断。可以采用i循环（strlen算长度），j计数，flag做标记。
// 当输入的字符串有空格的地方都令flag=0，然后不是空格的地方循环接下去如果到了空格位置就让flag变成1，j计数加一，表示空格前面就是一个单词，然后输出j就是单词数量。

int main()
{
	char a[N] = {0};
	int i, j = 0, flag = 0;
	printf("输入字符串:");
	gets(a);
	for(i = 0; i < strlen(a); i++)
	{
		if(a[i] == ' ')
		{
			flag = 0;
		}
		else
		{
			if(flag == 0)
			{
				j++;
				flag = 1;
			}
		}
	}
	printf("单词总数为%d\n", j);
}