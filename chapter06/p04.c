#include <stdio.h>
#include <stdlib.h>
#define MAX 1024
int main(int argc, char *argv[])
{
	if( 2 != argc ) {
		printf("Wrong parameter!\n");
		return 0;
	}
	int n = atoi(argv[1]), i = 0, j = 0;
	if( n < 0 )
		return 0;
	else if( n > MAX )
		n = MAX;
	char * const tmp = calloc(n + 1, sizeof(char));
// 0 is true, 1 is false
	for( tmp[0] = 1, tmp[1] = 1, tmp[2] = 0, i = 2; i < n + 1; ++i )
		if( 0 == tmp[i] )
			for( j = i << 1; j < n + 1; j += i )
				tmp[j] = 1;
	for( i = 1, j = 0; i < n + 1; ++i )
		if( 0 == tmp[i] )
			printf("%d%c", i, 0 == (7 & ++j) ? '\n' : '\t');
	printf("%s", 0 == (7 & j) ? "" : "\n");
	if( NULL != tmp )
		free(tmp);
	return 0;
}
