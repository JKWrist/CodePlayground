#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

char *mystrncpy(char *dst, const char *src, size_t n)
{
	assert(dst != NULL && src != NULL);

	char *dstCopy = dst;
	while (n && (*dst++ = *src++))
		n--;

	if (n) {
		while (--n)
			*dst++ = '\0';
	}

	return dstCopy;
}

int main(int argc, char* argv[])
{
	char dst[] = "dest";
	char *src = "src";
	//为避免内存覆盖（src长度大于dst长度），通常将n设置为目标字符串长度。
	printf("%s",mystrncpy(dst, src, sizeof(dst)));
	
	return 0;
}