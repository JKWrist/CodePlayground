#include <iostream>
#include <sys/fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;


#define MAX_BUFFER_LENGTH (1024)
char sg_arrReadBuffer[MAX_BUFFER_LENGTH];
string sg_strReadFIFOName  = "/tmp/systemcall_read_fifo";
string sg_strWriteFIFOName = "/tmp/systemcall_write_fifo";


int main(int argc, char *argv[]) 
{
//	int i = 0;
//	int iReadFd = 0, iWriteFd = 0, iSize = 0;
//	char cData = 0, cOK = 0, cFail = -1;
//
//	//FIFO存在先删掉
//	unlink(argv[1]);
//	
//	//生成一个有名管道
//	if(mkfifo(sg_strReadFIFOName.c_str(), 0666) < 0)
//	{
//		cout << "mkfifo systemcall fail" << endl;
//		return -1;
//	}
//	if(iReadFd = open(sg_strReadFIFOName.c_str(), O_RDWR) < 0)

	char arrBuffer[1024];
	
	int iRet, iNum;
	
	memset(arrBuffer, 0, sizeof(arrBuffer));
	FILE *fRead = popen("ifconfig eth0| grep RUNNING", "r");
	
	if(fRead != NULL)
	{
		iNum = fread(arrBuffer, sizeof(arrBuffer) - 1, fRead);
		if(iNum > 0)
		{
			iRet = 1;
		}
		else 
		{

		}
	}
}