#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define DUMP(func, call) \
	printf("%s: func = %p, called by = %p\n", __FUNCTION__, func, call)
 
 
void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *this_func, void *call_site)
{
	DUMP(this_func, call_site);
}
 
 
void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *this_func, void *call_site)
{
	DUMP(this_func, call_site);
}


int main (int argc, char** argv)
{
    int array[100];
    return array[100];
	// return 0;
}
