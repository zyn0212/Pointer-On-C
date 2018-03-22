#include <stdio.h>
#include <stdlib.h>
#define MAX 1024
int getIntegerArray(FILE *fp, int *s, int number);
int main(void)
{
	int i = 0, c = 0;
	while( !printf("Please input integer number:") || 1 != scanf("%d", &i) ) {
		printf("Wrong input, Please input a integer!\n");
		while( '\n' != (c = getchar()) && EOF != c )
			NULL;
	}
	if( i < 1 )
		return 0 & printf("Integer number < 1\n");
	int *s = (int *)malloc((i + 1) * sizeof(int));
	if( NULL == s )
		return 1;
	getIntegerArray(stdin, s, i);
	int j = 0;
	for( ; j < i + 1; ++j )
		printf("%d ", s[j]);
	free(s);
	return 0;
}
int getIntegerArray(FILE *fp, int *s, int number)
{
	if( NULL == fp || NULL == s || number < 1 )
		return 1;
	int i = 0, c = 0;
	for( *s++ = number; i < number; ++i )
		if( 1 != fscanf(fp, "%d", s + i) )
			while( '\n' != (c = getchar()) && EOF != c )
				NULL;
	return 0;
}
