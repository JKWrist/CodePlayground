#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	char name[30];
	int Chinese;
	int Math;
	int English;
}Student;

Student students[7];

void readData()
{
	FILE * file = fopen("mark.txt", "r");
	for (int i = 0; i < 7; i++)
	{
		fscanf(file, "%s", students[i].name);
		fscanf(file, "%d", &students[i].Chinese); //读入时不是数组记得写取地址符号
		fscanf(file, "%d", &students[i].Math);
		fscanf(file, "%d", &students[i].English);
	}
	fclose(file);
}

void displayData()
{
	for (int i = 0; i < 7; i++)
	{
		printf("%s\t", students[i].name);
		printf("%d\t", students[i].Chinese); 
		printf("%d\t", students[i].Math);
		printf("%d\t", students[i].English);
		printf("%d\n", students[i].Chinese + students[i].Math + students[i].English);
	}
}

int compare(const void *a, const void *b)
{
	Student* st1 = (Student*)a;
	Student* st2 = (Student*)b;
	int num1 = st1->Chinese + st1->Math + st1->English;
	int num2 = st2->Chinese + st2->Math + st2->English;
	return num1 - num2;
}

// bsearch 第一个填写key，第二个是数组中的元素值
int compare2(const void * key, const void * e)
{
	int *pnum1 = (int *)key;
	int num1 = *pnum1;
	Student *pS = (Student*) e;
	int num2 = pS->Chinese + pS->Math + pS->English;
	return num1 - num2;
}
int main(int argc, char *argv[]) 
{
	readData();
	qsort(students, 7, sizeof(Student), compare);
	displayData();
	
	//Len	77	68	45	190
	//Peter	59	68	78	205
	//Harry	78	66	67	211
	//Alice	62	73	88	223
	//Mickey	88	77	66	231
	//Lucy	87	78	87	252
	//Jerry	99	89	88	276
	int key = 223;	
	
	Student * s = bsearch(&key, students, 7, sizeof(Student), compare2);
	printf("%s\n", s->name);
		//查找元素， 数组， 数组大小， 数据长度， 比较函数（按照某种顺序排列，从小到大或者从大到小，二分查找， qsort之后再用）
	return 0;
}