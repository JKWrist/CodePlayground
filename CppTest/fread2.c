#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *stream;
	char msg[]="this is a test";
	char buf[20];
	
	//打开了这个文件
	if((stream=fopen("DUMMY.FIL","w+"))==NULL)
	{
		fprintf(stderr,"Can not open output file.\n");
		return 0;
	}
	/*write some data to the file*/
	fwrite(msg,1,strlen(msg)+1,stream);
	
	/*sizeof（char）=1 seek to the beginning of the file*/ 
	fseek(stream,0,SEEK_SET);
	
	/*read the data and display it*/
	fread(buf,1,strlen(msg)+1,stream);
	
	printf("%s\n",buf);
	fclose(stream);
	return 0;
}
