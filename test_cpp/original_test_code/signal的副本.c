#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_div0(int sig) {
	printf("看看我抓到了什么：%d\n", sig);
	exit(0);   
}

int main() {

	signal(SIGFPE, handle_div0);
	int i = 0;
	int a = 10;

	int c = a / i;
	return 0;
}