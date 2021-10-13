#include <stdio.h>
#include "test.h"
const int n = 10;
void func();
int main(){
	func();
	printf("main: %d\n", n);
	return 0;
}