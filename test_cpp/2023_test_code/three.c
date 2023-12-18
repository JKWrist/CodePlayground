#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int i_domain1_len = 0;
	int i_domain2_len = 1;
	int set_rules = ((i_domain1_len > 0) || (i_domain2_len > 0))? 1:0;
	printf("%d\n", set_rules);
	return 0;
}
