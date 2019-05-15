#include <stdio.h>
int main()
{
	int i = 0, m = 1, x = 1;
	while(1)
	{
		m = x;
		for(i = 0; i < 5; i++)
		{
			if((m - 1) % 5 == 0)
				m = (m - 1) / 5 * 4;
			else 
				break;
		}
		if(i == 5 && m > 0)
			break;
		x++;
	}
	printf("%d", x);
	return 0;
	
}