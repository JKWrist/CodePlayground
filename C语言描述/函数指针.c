#include <stdio.h>
int (*match)(void *key1, void *key2)

int main(int argc, char *argv[]) 
{
	match = match_int;
	
}