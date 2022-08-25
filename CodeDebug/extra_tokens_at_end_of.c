// directive_1.c
#include <stdio.h>

//WARNING: “extra tokens at end of #ifndef directive”。
//从字面上来看是"在#ifndef后面有无效的指令"

#if 0
#ifndef MIN
  #define MIN(x, y) ((x) > (y) ? (y) : (x)) 
#endif /**/x
#endif

#if 0
#ifndef MIN
  #define MIN(x, y) ((x) > (y) ? (y) : (x)) 
#endif
#endif

#if 0
#ifndef MIN(x, y)
  #define MIN(x, y) ((x) > (y) ? (y) : (x)) 
#endif
#endif

int main()
{
	printf("min val = %d\n", MIN(100, -1));

	return 0;
}