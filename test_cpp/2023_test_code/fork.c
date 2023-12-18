#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

static void __websig_child(int sig)
{
	pid_t wpid;

	while(1)
	{
		wpid = waitpid(-1, NULL, WNOHANG);
		if(wpid>0)
		{
			printf("child is quit, wpid==[%d]\n", wpid);
		}
		else if(wpid==0)
		{
			printf("child is living, wpid==[%d]\n", wpid);
			break;
		}
		else if(wpid==-1)
		{
			printf("no child is living, wpid==[%d]\n", wpid);
			break;
		}
	}
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2023-11-21 15:37:04
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    struct sigaction st_sig;
	sigaddset(&st_sig.sa_mask, SIGCHLD);
	st_sig.sa_flags = 0;
	st_sig.sa_handler = __websig_child;
    sigaction(SIGCHLD, &st_sig, NULL);


	pid_t pid1 = fork();
	// fork();
	// fork();
	// fork();
	if (0 == pid1)
	{
		sleep(2);
		printf("child 1\n");

		pid_t pid2 = fork();
		if (0 == pid2)
		{
			sleep(2);
			printf("child 2\n");
		}
		else
		{
			sleep(2);
			printf("child 3\n");
		}
	}
	else
	{
		printf("father 1\n");
		while(1);
	}
	return 0;
}
