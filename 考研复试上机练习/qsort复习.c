#include <stdio.h>
#include <stdlib.h>
int values[] = {40, 10, 100, 90, 20, 25};
const unsigned long VALUES_LEN = sizeof(values)/sizeof(values[0]);
const unsigned long VALUES_ITEM_SIZE = sizeof(values[0]);

int compare(const void * a, const void * b)
{
	return (*(int *)a -*(int *)b);
}

int main(int argc, char *argv[]) 
{
	int i;
	qsort(values, VALUES_LEN, VALUES_ITEM_SIZE, compare);
	
	for (i =0; i < VALUES_LEN; i++)
	{
		printf("%d ", values[i]);
	}
	putchar('\n');
	return 0;
}