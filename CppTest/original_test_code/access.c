#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h> 
 
int main() 
{ 
	if((access("test.bin",F_OK))!=-1) 
	{ 
		printf("文件 test.bin 存在. \n"); 
	} 
	else 
	{ 
		printf("test.bin 不存在! \n"); 
	} 
 
	if(access("test.bin",R_OK)!=-1) 
	{ 
		printf("test.bin 有可读权限\n"); 
	} 
	else 
	{ 
		printf("test.bin 不可读. \n"); 
	} 
 
	if(access("test.bin",W_OK)!=-1) 
	{ 
		printf("test.bin 有可写权限\n"); 
	} 
	else 
	{ 
		printf("test.bin 不可写. \n"); 
	} 
	
	if(access("test.bin",X_OK)!=-1) 
	{ 
		printf("test.bin 有可执行权限\n"); 
	} 
	else 
	{ 
		printf("test.bin 不可执行. \n"); 
	} 
 
	return 0; 
} 