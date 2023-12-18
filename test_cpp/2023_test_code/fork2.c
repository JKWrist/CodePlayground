#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2023-11-27 10:50:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/

// 使用两次fork来解决僵尸进程问题的常见方法
// 创建一个孙子进程，让孙子进程成为父进程，
// 而原始的子进程则可以被init进程（PID为1）所收养，从而避免成为僵尸进程。以下是一个简单的示例代码：

int test01()
{
	pid_t child1, child2;
	printf("1111 %d %d\n", getpid(), getppid());
	child1 = fork();

	if (child1 < 0)
	{
		// 错误处理
		fprintf(stderr, "Fork failed");
		return 1;
	}
	else if (child1 > 0)
	{
		// 父进程
		printf("1111 %d %d\n", getpid(), getppid());
		wait(NULL);  // 等待第一个子进程
		while (1);
	
	}
	else
	{
		printf("2222 %d %d\n", getpid(), getppid());
		// 第一个子进程
		child2 = fork();  // 创建第二个子进程

		if (child2 < 0)
		{
			// 错误处理
			fprintf(stderr, "Fork failed");
			return 1;
		}
		else if (child2 > 0)
		{
			// 第一个子进程退出
			printf("1111 aaa exit %d %d\n", getpid(), getppid());
			exit(0);
		}
		else
		{
			// 孙子进程
			// 执行相应的任务
			printf("1111 bbb exit %d %d\n", getpid(), getppid());
			sleep(2);
			printf("1111 bbb exit %d %d\n", getpid(), getppid());
			exit(0);
		}
	}

	return 0;
}

int main()
{	
	test01();
	return 0;
}
