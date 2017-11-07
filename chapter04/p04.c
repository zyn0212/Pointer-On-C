#include <stdio.h>
#include <string.h>
static void copy_n(char *dst, char *src, int n);
int main(int argc, char *argv[])
{
	char dst[30] = "nihaoshijie,wo shi zhaoyining";
	char src[50] = "wo ai sun li na";
	printf("dst = %s\n", dst);
	copy_n(dst + 1, dst, 20);
	printf("dst = %s\n", dst);
	return 0;
}
static void copy_n(char *dst, char *src, int n)
{
	int i = 0, len = strlen(src);
	if( src > dst || dst - src > n )
		for( i = 0; i < n; ++i )
			dst[i] = i < len ? src[i] : '\0';
	else if( dst != src )
		for( i = n - 1; i >= 0; --i )
			dst[i] = i < len ? src[i] : '\0';
	else
		;
	return;
}
