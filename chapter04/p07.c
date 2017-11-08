#include <stdio.h>
static void deblank(char *src);
int main(void)
{
	char src[100];
	if( NULL == fgets(src, 100, stdin) ) {
		printf("get chars failed!\n");
		return 1;
	}
	deblank(src);
	printf("%s", src);
	return 0;
}
static void deblank(char *src)
{
	if( '\0' == *src )
		return;
	char *tmp = ++src;
	while( '\0' != *src )
		if( ' ' != *(src - 1) || ' ' != *src )
			*tmp++ = *src++;
		else
			src++;
	*tmp = '\0';
	return;
}
