#include "./config.h"

int main()
{
    char *filePath = "./config.txt";
    int len = getFileLines(filePath);
    printf("有效的行数，%d\n", len);

    struct ConfigInfo *configInfo = NULL;
    parseFile(filePath, len, &configInfo);

    printConfiginfo(configInfo, len);
    freeConfigInfo(configInfo);
    
    configInfo = NULL;
    return 0;
}
