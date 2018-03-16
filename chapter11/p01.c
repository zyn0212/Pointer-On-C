#include <stdlib.h>
char *calloc_z(int n, int size);
int main(void)
{
	return 0;
}
char *calloc_z(int n, int size)
{
	if( n < 1 || size < 1 )
		return NULL;
	char *ret = malloc(n * size);
	if( NULL == ret )
		return NULL;
	int i = 0;
	for( ; i < n * size; ++i )
		*(ret + i) = 0;
	return ret;
}
