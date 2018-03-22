#include <stdlib.h>
#include <stdio.h>
#define BLOCKSIZE 16
char *getString(void);
int main(void)
{
	char *s = getString();
	if( NULL != s ) {
		printf("%s\n", s);
		free(s);
	}
	return 0;
}
char *getString(void)
{
	int c = 0, i = 0, blockn = 1;
	char *ret = (char*)calloc(BLOCKSIZE, sizeof(char)), *tmp = NULL;
	if( NULL == ret )
		return NULL;
	while( '\n' != (c = getchar()) ) {
		ret[(blockn - 1) * BLOCKSIZE + i++] = c;
		if( i >= BLOCKSIZE ) {
			tmp = ret;
			ret = realloc(ret, ++blockn * BLOCKSIZE * sizeof(char));
			if( NULL == ret ) {
				free(tmp);
				printf("Fatal Error: No enough space to save input string!\n");
				return NULL;
			}
			i = 0;
		}
	}
	ret[(blockn - 1) * BLOCKSIZE + i++] = '\0';
	return ret;
}
