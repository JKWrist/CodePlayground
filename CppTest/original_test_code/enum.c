#include<stdio.h>
int main()
{	
	enum week//定义一个星期的枚举类型week
	{
		Sun,
		Mon,
		Tue,
		Wed,
		Thu,
		Fri,
		Sat
	};

	enum week day;//定义枚举变量 day
	printf("%d\n",sizeof(day));
	int i;//定义整形变量 i
	while(1)
	{
		usleep(5000);
		printf("请输入0~6之间的一个数字：\n");
		scanf("%d",&i);//输入一个 i
		day = i;//强制类型转换，将整形的i 转换为枚举型
		switch (day)//判断枚举变量day的值
		{
			case 0:printf("星期日\n"); break;
			case 1:printf("星期一\n"); break;
			case 2:printf("星期二\n"); break;
			case 3:printf("星期三\n"); break;
			case 4:printf("星期四\n"); break;
			case 5:printf("星期五\n"); break;
			case 6:printf("星期六\n"); break;
		}
	}
	
	

	return 0;
}
