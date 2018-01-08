#include <stdio.h>
#include <stdlib.h>
#define MAX (1 << 21)
int main(int argc, char *argv[])
{
	if( 2 != argc ) {
		printf("Wrong parameter!\n");
		return 0;
	}
	int n = atoi(argv[1]), i = 0, j = 0, count = 1, step = 1;
	if( n < 0 )
		return 0;
	else if( n > MAX )
		n = MAX;
	char * const tmp = calloc(n + 15 >> 4, sizeof(char));
// 0 is true, 1 is false
// 15 13 11 9 7 5 3 1
// 7  6  5  4 3 2 1 0
	for( i = 1; i < n + 1 >> 1; ++i )
		if( 0 == (tmp[i >> 3] & 1 << (i & 7)) )
			for( j = i + (i << 1) + 1; j < n + 1 >> 1; j += (i << 1) + 1)
				tmp[j >> 3] |= 1 << (j & 7);
	for( i = 1, j = 1; i < n + 1 >> 1; ++i )
		if( 0 == (tmp[i >> 3] & 1 << (i & 7)) ) {
			++j;
			if( (i << 1) + 1 > step * 1000 )
				++step,printf("%d\n", j - count), count = j - 1;
		}
	++step,printf("%d\n", j - count), count = j - 1;
	if( NULL != tmp )
		free(tmp);
	return 0;
}
