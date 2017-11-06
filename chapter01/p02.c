#include <stdio.h>
int main(void)
{
	int i = 0, c = 0, last = '\n';
	for( c = getchar(); EOF != c; c = getchar() ) {
		if( '\n' == last )
			printf("%02d\t", ++i);
		last = putchar(c);
	}
	return 0;
}
