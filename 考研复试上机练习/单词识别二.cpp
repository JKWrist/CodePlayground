测试样例简直有毒。。4x4)和(at都算单词
 
	#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct str0 {
	char ch[1000];
	int count;
	int flag;
} str1;
 
	str1 str[1000];
str1 temp;
int main() {
 
		int i = 0;
	while(scanf("%s", str[i].ch) != EOF) {
		i++;
	}
	int sum = i;
	int j;
	for(i = 0; i < sum; i++) {
		str[i].flag = 1; //一开始都不是克隆的
	}
	for(i = 0; i < sum; i++) {
		int len = strlen(str[i].ch);
		for(j = 0; j < len; j++) {
			if(str[i].ch[j] >= 'A' && str[i].ch[j] <= 'Z') {
				str[i].ch[j] = str[i].ch[j] - 'A' + 'a';
				//变成小写字母
			} else if(str[i].ch[j] < 'a' || str[i].ch[j] > 'z') {
				//不是小写字母
				//删除这个字符
				if((str[i].ch[j]=='.'||str[i].ch[j]==',')&&j==len-1)
					str[i].ch[j] = '\0';
		}
	  }
	}
 
		for(i = 0; i < sum; i++) {
		str[i].count = 1;
		if(str[i].flag == 1) {  //这个不是克隆的，就可以记数了
			for(j = i + 1 ; j < sum; j++) {
				if(strcmp(str[i].ch, str[j].ch) == 0) {
					str[i].count++;
					str[j].flag = 0; //这个是克隆的！
				}
			}
		}
	}
	//记数都完成了，现在要字典序输出！
	//冒泡排序
	for(i = 0; i < sum - 1; i++) {
		for(j = 0; j < sum - 1 - i; j++) {
			if(strcmp(str[j].ch, str[j + 1].ch) > 0) { //前面的字符串更大
				//交换
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
	//现在开始输出
	for(i = 0; i < sum; i++) {
		if(str[i].flag == 1)
			printf("%s:%d\n", str[i].ch, str[i].count);
	}
	return 0;
}