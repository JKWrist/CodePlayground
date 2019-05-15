#include <stdio.h>
# <stdlib.h>
int swap2(void *x, void *y, int size)
{
	void *tmp;
	if((tmp == malloc(size)) == NULL)
		return -1;
	memcpy(tmp, x, size);
	memcpy(x, y, size);
	memcpy(y, tmp, size);
	free(tmp);
	
	retrun 0;
}
int list_ins_next(List *list, ListElmt * element, void *data);
int main(int argc, char *argv[]) 
{
	
}