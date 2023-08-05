#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * power - Calculate the power of number.
 * @param base: Base value.
 * @param exponent: Exponent value.
 *
 * @return base raised to the power exponent.
 */
double power(double base, int exponent)
{
    int result = base;
    int i;

    if (exponent == 0) {
        return 1;
    }
    
    for(i = 1; i < exponent; ++i){
        result = result * base;
    }

    return result;
}

int getDnsIp(char *pIP1, char *pIP2, int iIpLen, char cDot)
{
	char tmpbuf[256] = {0};
	FILE *fp = NULL;
	int count = 0;

	if ((fp = fopen("/var/resolv_backup.conf", "r")) == NULL)
	{
		printf("fopen resolv_backup.conf error\n");
	}

	while(fgets(tmpbuf, sizeof(tmpbuf), fp) != NULL)
	{
		if (strchr(tmpbuf, cDot))
		{
			if (0 == count)
			{
				if (sscanf(pIP1, "%s", tmpbuf) != 1)
				{
					printf("sscanf pIP1 error\n");
					return -1;
				}
				count++;
			}
			else
			{
				if (sscanf(pIP2, "%s", tmpbuf) != 1)
				{
					printf("sscanf pIP2 error\n");
					return -1;
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}
