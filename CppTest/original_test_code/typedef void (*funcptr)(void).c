#include <stdio.h>
typedef void (*funcptr)();
void hello(void) { printf("你好!\n"); }
void bye(void) { printf("再见！\n"); }
void ok(void) { printf("好的！\n"); }
void speak(int id)
{
	funcptr words[3] = {&hello,&bye,&ok};
	funcptr fp = words[id];
	(*fp)();
}
int main()
{
	speak(0);
	speak(1);
	speak(2);
	printf("%p %p %p\n", &speak, speak, *speak);
	return 0;
}