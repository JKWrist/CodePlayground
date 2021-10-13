#include <stdio.h>
#include <string.h>

char resultStr[1024] = {0};

void write_formula_to_file()
{
    FILE *pFile = fopen("fourOperation.txt", "w");
    if (pFile == NULL)
    {
        printf("file open error!\n");
    }
    fputs("1+2\n", pFile);
    fputs("2*3\n", pFile);
    fputs("9-6\n", pFile);
    fputs("9/2\n", pFile);
    fputs("9%6\n", pFile);
    fclose(pFile);
}

int calculate(int a, char cOperator, int b)
{
    switch (cOperator)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '%':
        return a % b;
        break;
    }

    return -1;
}

void get_result_buffer()
{
    char tmpStr[1024] = {0};
    char formulaStr[1024] = {0};
    int a = 0, b = 0;
    char c = 0;

    FILE *pFile = fopen("fourOperation.txt", "r");
    if (pFile == NULL)
    {
        printf("file open error!\n");
    }

    while (1)
    {
        memset(tmpStr, 0, sizeof(tmpStr));
        fgets(tmpStr, 1024, pFile);
        sscanf(tmpStr, "%d%c%d=\n", &a, &c, &b);
        printf("%d%c%d=\n", a, c, b);
        if (feof(pFile))
        {
            break;
        }

        memset(tmpStr, 0, sizeof(tmpStr));
        sprintf(tmpStr, "%d%c%d=%d\n", a, c, b, calculate(a, c, b));
        printf("tmpStr %s\n", tmpStr);
        strcat(resultStr, tmpStr);
        printf("resultStr %s\n", resultStr);
    }
    fclose(pFile);
}

void write_result_to_file()
{
    FILE *pFile = fopen("fourOperationResult.txt", "w");
    if (NULL == pFile)
    {
        printf("fopen error\n");
    }

    fputs(resultStr, pFile);
    fclose(pFile);
}

int main()
{
    write_formula_to_file();
    get_result_buffer();
    write_result_to_file();
    return 0;
}