#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char buf[512];
	sscanf("123456 ", "%s", buf);
	printf("%s\n", buf);
	
	sscanf("123456 ", "%4s", buf);
	printf("%s\n", buf);
	
	sscanf("123456 ab^cdedf", "%[^ ]", buf);
	printf("%s\n", buf);
	
	sscanf("123456abcdedfBCDEF", "%[1-9a-z]", buf);
	printf("%s\n", buf);
	
	sscanf("iios/12DDWDFF@122", "%*[^/]/%[^@]", buf);
	printf("%s\n", buf);
	
	sscanf("hello, world", "%*s%s", buf);
	printf("%s\n", buf);
	
	int day, year, month;
	char dtm[100];

	strcpy( dtm, "1989 03 25");
	sscanf( dtm, "%d %d %d",  &year, &month, &day);

	printf("%d, %d, %d\n",year, month, day);
	
     char  tokenstring[] = "15 12 14...";
     char  s[81];
     char  c;
     int   i;
     float fp;
	 // Input various data from tokenstring:
     // max 80 character string:
     sscanf( tokenstring, "%80s", s ); // C4996
     sscanf( tokenstring, "%c", &c );  // C4996
     sscanf( tokenstring, "%d", &i );  // C4996
     sscanf( tokenstring, "%f", &fp ); // C4996
     // Note: sscanf is deprecated; consider using sscanf_s instead 
	// Output the data read
     printf( "String    = %s\n", s );
     printf( "Character = %c\n", c );
     printf( "Integer:  = %d\n", i );
     printf( "Real:     = %f\n", fp );
}