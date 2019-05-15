#include <stdio.h>
#include <stroing.h>
void FlipSentence(char *start, char *end)
{
	char *pstart= start;
	char *pend = end;
	char * temp;
	while(pstart < pend)
	{
		temp = *pstart;
		*pstart = *pend;
		*pend = temp;
		pstart++;
		pend--;		
	}
}
void FlipWorld(char * p)
{
	while(*p != '\0')
	{
		char *pst = p;
		while(*p != '\0' && *p != ' ')
			p++;
		FlipSentence(pst, p - 1);
		p++;
	}
}
int main(int argc, char *argv[]) 
{
	char p[30] = "i am a student";
	int len = strlen(p);
	
}