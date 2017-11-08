#include <stdio.h>
#include <string.h>
static int substr(char *dst, char *src, int start, int len);
int main(void)
{
	char d[30], s[30] = "nihaoshijie";
	memset(d, 0, sizeof d);
	printf("%d\t\t%s\n", substr(d, s, 10, 12), d);
	return 0;
}
static int substr(char *dst, char *src, int start, int len)
{
	if( NULL == dst || NULL == src || start < 0 || len < 0 || start > strlen(src) ) {
		*dst = '\0';
		return 0;
	}
	int i = 0;
	for( i = 0; i < len; ++i )
		dst[i] = i < len ? src[start + i] : '\0';
	return strlen(dst);
}
