#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

//搜索 指定目录下的所有文件及其子目录下的文件
void get_file_name(char *dirPath)
{
	DIR *dir = opendir(dirPath);
	if (dir == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	chdir(dirPath); //进入到当前读取目录
	struct dirent *ent;
	while ((ent = readdir(dir)) != NULL)
	{
		if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
		{
			continue;
		}
		int size = strlen(ent->d_name);

		if (strcmp((ent->d_name + (size - 2)), ".c") != 0) //只存取.c 扩展名的文件名
			continue;

		struct stat st;
		stat(ent->d_name, &st);

		if (S_ISDIR(st.st_mode)) //如果是子目录，继续递归搜索
		{
			get_file_name(ent->d_name);
		}
		else
		{
			printf("%s\n", ent->d_name);
		}
	}

	closedir(dir);
	chdir(".."); //返回当前目录的上一级目录
}

int main(int argc, char *argv[])
{
	get_file_name("..");
	return 0;
}