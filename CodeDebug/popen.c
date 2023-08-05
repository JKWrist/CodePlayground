#include <stdio.h>
#include <stdlib.h>

void getPopenData(char* command, char* data, int data_len)
{
	char* tmp_data = NULL;
	size_t size = 0;
	FILE* fp = popen(command, "r");
	if(fp == NULL)
	{
		printf("Failed to run command %s \n",command);
		exit(1);
	}

	char buffer[1024];
	while(fgets(buffer, sizeof(buffer), fp))
	{
		size_t len = strlen(buffer);
		tmp_data = realloc(tmp_data, size + len + 1);
		if(tmp_data == NULL)
		{
			printf("Failed to allocate memory\n");
			exit(1);
		}
		memcpy(tmp_data + size, buffer, len);
		size += len;
	}
	tmp_data[size] = '\0';
	pclose(fp);

	memset(data, 0, sizeof(*data));
	strncpy(data, tmp_data, data_len - 1);
	free(tmp_data);
}

int main()
{
	char buf[1024] = {0};
	getPopenData("ls -l", buf, sizeof(buf));
	printf("%s", buf);
	return 0;
}