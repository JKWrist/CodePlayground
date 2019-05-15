#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
	char ** seq; //组合
	int * code; //标识
	int size;
	int max_size;
}Dictionary;

void insert_seq(Dictionary* dict, char * seq)
{
	int i = dict->size;
	dict->
}
void init_dictionary(Dictionary* dict, int max_size)
{
	dict->max_size = max_size;
	dict->size = 0;
	dict->seq = malloc(sizeof(char *) * max_size);
	dict->code = malloc(sizeof(int) * max_size);
}
int main(int argc, char *argv[]) 
{
	
}