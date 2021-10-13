//linux下c语言如何实现判断一个路径是文件还是文件夹呢？c语言如何实现判断一个路径是文件还是文件夹呢？ 我只获取了一个路径下的文件，但是由于需要，不知道如何判断获取的是文件夹与否，请DX指教，谢谢。opendir 是打开目录，打开成功说明是目录，打开失败就，尝试fopen~~~回复 
//
//#2 lsupper 的帖子这样也是个办法
//IP地址详细解析
//
//，但是如果文件多时，每个都去判断一下，时间复杂度太大了吧，有没有其他的办法，还得请DX们帮帮忙。回复 #1 hxh88888888 的帖子struct stat 
//info;
stat(pathhttp://www.tx1019.com,&info);
if(S_ISDIR(info.st_mode))
printf("This is a directory");

//[ 本帖最后由 ghostgorst 于 2009-9-2 17:51 编辑 ]你可以用lstat()函数得到属性再判断原帖由 hxh88888888 于 2009-9-2 17:41 发表 http://bbs3.chinaunix.net/images/common/back.gif
//这样也是个办法，但是如果文件多时，每个都去判断一下，时间复杂度太大了吧，有没有其他的办法，还得请DX们帮帮忙。
//
//你想太多了，用4楼的办法挺好顺便提醒下小问题：
//
//folder\folder2\是一个目录，
//stat( "folder\\folder\\", &st ) 结果是什么呢？windows上给出stat错误，多了个\原帖由 hxh88888888 于 2009-9-2 17:25 发表 http://bbs3.chinaunix.net/images/common/back.gif
//c语言如何实现判断一个路径是文件还是文件夹呢？ 我只获取了一个路径下的文件，但是由于需要，不知道如何判断获取的是文件夹与否，请DX指教，谢谢。

#include <sys/stat.h>
#include <unistd.h>
// 目录
int isdir(char *path)
{
struct stat buf;
int cc;
cc=stat(path,&buf);
if(http://www.cztongda.com!cc && (buf.st_mode & S_IFDIR)) return(1);
return(cc);
}
// 可读普通文件
int isrfile(char *path)
{
struct stat buf;
int cc;
int euid,egid;
cc=stat(path,&buf);
if(!cc) {
if((buf.st_mode & S_IFMT) != S_IFREG) return 0;
euid=geteuid();
egid=getegid();
if(euid==0) {
if(buf.st_mode & S_IRUSR || buf.st_mode & S_IRGRP ||
buf.st_mode & S_IROTH)
return 1;
else return 0;
}
if((buf.st_mode & S_IROTH)!=0) return 1;
if((buf.st_gid == egid) && ((buf.st_mode & S_IRGRP)!=0))
return 1;
if((buf.st_uid == euid) && ((buf.st_mode & S_IRUSR)!=0))
return 1;

}
return cc;
}