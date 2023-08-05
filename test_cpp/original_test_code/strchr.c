#include <stdio.h>

#include <string.h>

int getDnsIp(char *pIP1, char *pIP2, int iLen, char cDot)
{
	char tmpbuf[256] = {0};
	FILE *fp = NULL;
	int count = 0;

	if ((fp = fopen("ip.txt", "r")) == NULL)
	{
		printf("fopen resolv_backup.conf error\n");
		return -1;
	}

	while( fgets(tmpbuf, sizeof(tmpbuf), fp) != NULL)
	{
		if (strchr(tmpbuf, cDot))
		{
			printf("tmpbuf %s\n",tmpbuf);
			if (strchr(tmpbuf, '\n'))
			{
				int iN = strlen(tmpbuf);
				tmpbuf[iN - 1] = '\0';
			}

			if (0 == count)
			{
				strncpy(pIP1, tmpbuf, iLen);
				count++;
			}
			else
			{
				strncpy(pIP2, tmpbuf, iLen);
			}
		}
	}

	fclose(fp);
	return 1;
}

int main()
{
    char v4dns1[16] = {0}, v4dns2[16] = {0};
    char v6dns1[48] = {0}, v6dns2[48] = {0};

    getDnsIp(v4dns1, v4dns2, sizeof(v4dns1), '.');
	getDnsIp(v6dns1, v6dns2, sizeof(v6dns1), ':');

    printf("%s\n%s\n", v4dns1, v4dns2);

	printf("%s\n%s\n", v6dns1, v6dns2);
}
