#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int L, M, i, j = 0,start, end, n_start, n_end,del_num, left_num;
	scanf("%d%d",&L, &M);
	int s[10000];
	while(L != 0 && M != 0)
	{
		scanf("%d%d", &start, &end);
		for(i = 1; i < M; i++)
		{
			scanf("%d%d",n_start, n_end);
			if(n_start < start)
				start = n_start;
			if(n_end > end)
				end = n_end;
		}
		del_num = end-start + 1;
		left_num = L
	}
	del_num = end-start+1;
	
}