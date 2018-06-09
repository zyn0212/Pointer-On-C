#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 10
static int getrand(void);
int main(void)
{
	srand(time(0));
	int result[MAX][MAX];
	memset(result, 0, sizeof result);
	int i = 0, j = 2, last = 0, current = 0;
	for( ; j < 11; ++j ) {
		for( i = 0; i < 10000; ++i ) {
			current = getrand() % j;
			printf("%d%c", current, 0 == (i + 1 & 0x3F) ? '\n' : ',');
			if( i > 0 )
				++result[current][last];
			last = current;
		}
		putchar('\n');
		for( i = 0; i < j; ++i ) {
			for( current = 0; current < j; ++current )
				printf("%d\t", result[i][current]);
			putchar('\n');
		}
	}
	return 0;
}

static int getrand(void)
{
	int retvalue = 0;
	int i = 0;
	for( ; i < 31; ++i )
		retvalue |= (rand() & 1) << i;
	return retvalue;
}
