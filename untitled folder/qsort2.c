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
		printf("%d\n", students[i].English);
	}
}

int compare(const void *a, const void *b)
{
	Student * st1 = (Student *)a;
	Student * st2 = (Student *)b;
	int num1 = st1->Chinese;
	int num2 = st2->Chinese;
	if(num1 - num2 < 0)
		return 1;
	else {
		return -1;
	}
}

int main(int argc, char *argv[]) 
{
	readData();
	displayData();
	qsort(students, 7, sizeof(Student), compare);
	printf("*********************\n");
	displayData();
	return 0;
}