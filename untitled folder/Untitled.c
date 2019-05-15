#include <stdio.h>
#include <math.h>
const double eps = 1e-8;
#define Equ(a,b) ((fabs((a)- (b))) < (eps))
int main(int argc, char *argv[]) 
{
	double db1 = 4 * asin(sqrt(2.0) / 2);
	double db2 = 3 * asin(sqrt(3.0) / 2);
	if(db1 == db2)
		printf("true");
	else 
		printf("false\n");
		
	if(Equ(db1, db2))
		printf("true");
	else 
		printf("false");	
}