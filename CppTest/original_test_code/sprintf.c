// crt_sprintf.c
// compile with: /W3
// This program uses sprintf to format various

//data and place them in the string named buffer.
// 程序使用sprintf 将各种数据格式化后置于字符数组buffer中
#include <stdio.h>
int main( void )

{
	char  buffer[200], s[] = "computer", c = 'l';
	int   i = 35, j;
	float fp = 1.7320534f;
	// 格式化并打印各种数据到buffer
	j  = sprintf( buffer,     "   String:    %s\n", s ); // C4996
	j += sprintf( buffer + j, "   Character: %c\n", c ); // C4996
	j += sprintf( buffer + j, "   Integer:   %d\n", i ); // C4996
	j += sprintf( buffer + j, "   Real:      %f\n", fp );// C4996
	
	printf( "Output:\n%s\ncharacter count = %d\n", buffer, j );
		
		
//	char * a = 32;
//	printf("atoi(a) = %d\n", atoi(a));
	
	char * p = 0;
	printf("p = %s\n" , p);
	printf("asdasdasda\n");
	printf("aaassdasdasd%c\n", '\0');
	return 0;
}