
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/************************************************
* Propose: isPorcessExist()
*   check is process exist with given name and customizable rules (e.g: process status, process runtime argument, etc.)
* 
* Parameter:
*   char* name                    process executable file name
*   int (*match_fn)(char *line)   customizable match function
*                                 input:  a ps command result line, whose process name match argument 1.
*                                 output: -1: error, 0: not match, 1: match
*   pid_t* pid                    if there's process match, return the process pid, otherwise, it is not used.
*
* Return:
*       -1: internal error
*        0: process matching name and customizable rule is not running
*        1: process matching name and customizable rule is running
* 
* Author:
*   patrick_cai
*************************************************/
int isPorcessExist(char *name, int (*match_fn)(char *line), pid_t *pid)
{
	FILE *fp = NULL;
	char cmd[256] = {0}, line[256] = {0};
	int exist = 0;
	volatile pid_t tmp_pid = 0;

	if(!name || !pid)
		return -1;
	printf("111 tmp_pid:%d\n", tmp_pid);
	printf("111 pid:%d\n", *pid);
	*pid = 0;
	printf("222 tmp_pid:%d\n", tmp_pid);
	printf("222 pid:%d\n", *pid);
	snprintf(cmd, sizeof(cmd), "ps -elf | grep %s | grep -v grep", name);
	fp = popen(cmd, "r");
	if(fp)
	{
		while(fgets(line, sizeof(line), fp)!=NULL && exist==0)
		{
			char buf[256] = {0}, proc_name[256] = {0};
			FILE *proc_fp = NULL;

			sscanf(line, "%d %*s", &tmp_pid);
			printf("tmp_pid:%d\n", tmp_pid);

			snprintf(proc_name, sizeof(proc_name), "/proc/%d/comm", tmp_pid);
			proc_fp = fopen(proc_name, "r");
			if(proc_fp==NULL)
				continue;
			else{
				char *_ptr = NULL;

				fgets(buf, sizeof(buf), proc_fp);
				fclose(proc_fp);
				printf("%s: %s\n", proc_name, buf);
				if((_ptr=strstr(buf, "\n"))!=NULL)
					*_ptr = '\0';
			}

			printf("buf:[%s], name:[%s]\n", buf, name);
			if(strcmp(buf, name))
				continue;

			//match (*match_fn)
			if(!match_fn || match_fn(line)==1) {
				exist = 1;
				break;
			}
		}
		pclose(fp);
	}else{
		exist = -1;
	}

	if(exist)
		*pid = tmp_pid;
	printf("333 tmp_pid:%d\n", tmp_pid);
	printf("333 pid:%d\n", *pid);
	return exist;
}


/****************************************************************
 *  函数名称：
 *  创建日期：2022-12-01 15:43:39
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int start_ahsapd()
{
	int ret;
	pid_t pid = 0;
	ret = isPorcessExist("getty", NULL, &pid);
	ret = isPorcessExist("sleep", NULL, &pid);
	ret = isPorcessExist("sshd", NULL, &pid);
	return 0;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-12-01 15:43:39
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	start_ahsapd();
	return 0;
}
