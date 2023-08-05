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

int getDnsIp_test(char *pIP, int pos, int iLen)
{
	if (NULL == pIP)
	{
		return -1;
	}

	char tmpbuf[256] = {0};
	FILE *fp = NULL;
	int count = 1;
	if ((fp = fopen("conf.txt", "r")) == NULL)
	{
		printf("fopen resolv.conf error\n");
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

			printf("cout %d pos %d\n", count, pos);
			if (1 == count && 1 == pos)
			{
				strncpy(pIP, tmp + strlen(pNameServer), iLen);
			}
			else if(2 == count && 2 == pos)
			{
				strncpy(pIP, tmp + strlen(pNameServer), iLen);
			}
			count++;
		}
	}
	fclose(fp);

	if(0 == strlen(tmpbuf))
		return 0;
	else
		return 1;
}

int main()
{
	char v4dns1[INET_ADDRSTRLEN] = {0}, v4dns2[INET_ADDRSTRLEN] = {0};
	char v6dns1[INET6_ADDRSTRLEN] = {0}, v6dns2[INET6_ADDRSTRLEN] = {0};

	getDnsIp(v4dns1, v4dns2, sizeof(v4dns1));
	printf("v4dns1 %s\n", v4dns1);
	printf("v4dns2 %s\n", v4dns2);

	getDnsIp_test(v4dns1, 1, sizeof(v4dns1));
	printf("v4dns1 %s\n", v4dns1);
	getDnsIp_test(v4dns1, 2, sizeof(v4dns1));
	printf("v4dns1 %s\n", v4dns1);
	return 0;
}
