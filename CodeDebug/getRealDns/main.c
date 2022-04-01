#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INET_ADDRSTRLEN   32
#define INET6_ADDRSTRLEN  64

int getDnsIp(char *pIP1, char *pIP2, int iLen)
{
	if (NULL == pIP1 || NULL == pIP2)
	{
		return -1;
	}

	char tmpbuf[256] = {0};
	FILE *fp = NULL;
	int count = 0;

	if ((fp = fopen("conf.txt", "r")) == NULL)
	{
		printf("fopen resolv_backup.conf error\n");
		return -1;
	}

	const char * pNameServer = "nameserver ";
	while (fgets(tmpbuf, sizeof(tmpbuf), fp) != NULL)
	{
		char * tmp = strstr(tmpbuf, pNameServer);
		if (tmp)
		{
			if (strchr(tmpbuf, '\n'))
			{
				int iN = strlen(tmpbuf);
				tmpbuf[iN - 1] = '\0';
			}
			if (0 == count)
			{
				strncpy(pIP1, tmp + strlen(pNameServer), iLen);
				count++;
			}
			else
			{
				strncpy(pIP2, tmp + strlen(pNameServer), iLen);
			}
		}
	}

	fclose(fp);
	return 1;
}

int main()
{
	char v4dns1[INET_ADDRSTRLEN] = {0}, v4dns2[INET_ADDRSTRLEN] = {0};
	char v6dns1[INET6_ADDRSTRLEN] = {0}, v6dns2[INET6_ADDRSTRLEN] = {0};

	getDnsIp(v4dns1, v4dns2, sizeof(v4dns1));
	printf("v4dns1 %s\n", v4dns1);
	printf("v4dns2 %s\n", v4dns2);

	return 0;
}
