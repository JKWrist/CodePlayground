#include<stdio.h>
#include<string.h>
#include<stdlib.h>
  
struct deal{
	char str[30];  //单词
	int num;  //单词出现的次数
};
  
int cmp(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
  
int main(){
	struct deal word[300];
	char ch;int i=0,j=0;
	word[0].num=1;
	int flag1=0,flag2=0;
	while(1){
		ch=getchar();
		if(ch>='A'&&ch<='Z')//大写字母
			ch=ch-'A'+'a';
		if(ch!=' '&&ch!=','&&ch!='.'&&ch!='\n'){//小写字母
			word[i].num=1;
			flag1=0;flag2=0;
			word[i].str[j]=ch;
			j++;
			word[i].str[j]='\0';
		}else if(ch!='.'&&ch!='\n'){//逗号或空格
			i++;flag1=0;flag2=0;
			word[i].num=0;
			j=0;
		}else if(ch=='.'){//句号
			flag1=1;
		}else{  //ch=='\n' 回车
			flag2=1;
		}
  
		if(flag1&&flag2) //停止标志
			break;   //相当于把这句话遍历完了才结束
	}
	int n=i+1;
	qsort(word,n,sizeof(word[0]),cmp);
	//1 待排序数组首地址
	//2 数组中待排序元素数量 3 各元素的占用空间大小 4 指向函数的指针
  
	for(i=0;i<n;i++)
	{
		if(strcmp(word[i].str,word[i+1].str)==0)
		{
			word[i+1].num=word[i].num+1;
			word[i].num=0;
		}
	}
  
	for(i=0;i<n;i++){
		if(word[i].num!=0&&word[i].str[0]!='\0')
			printf("%s:%d\n",word[i].str,word[i].num);
	}
  
}