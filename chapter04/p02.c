#include <stdio.h>
#include <string.h>
int main(void)
{
	char Result[101];
	memset(Result, 0, sizeof Result);
	int i = 0, j = 0;
	for( i = 2; i <= 100; ++i )
		if( 1 != Result[i] )
			for( j = i << 1; j <= 100; j += i )
				Result[j] = 1;
	for( i = 1, j = 0; i <= 100; i += 1 )
		if( 0 == Result[i])
			printf("%3d\t%s", i, 0 == ++j % 5 ? "\n" : "");
	printf("\n");
	return 0;
}
