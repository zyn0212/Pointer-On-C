#include <stdio.h>
#define LINEMAX 20
int main(int argc, char *argv[])
{
	int lineno = 1, c = 0, count = 0;
	if( 1 == argc ) {
		printf("01:\t");
		while( EOF != (c = getchar()) ) {
			putchar(c), ++count;
			if( '\n' == c )
				printf("\n%02d:\t", ++lineno);
			else if( LINEMAX == count )
				count = 0 & printf("\n%s:\t", "----");
		}
	}
	else
		while( --argc > 0 ) {
			printf("Deal file named:%s\n01:\t", argv[argc]);
			FILE *fp = fopen(argv[argc], "r");
			if( NULL == fp )
				continue;
			while( EOF != (c = fgetc(fp)) ) {
				putchar(c), ++count;
				if( '\n' == c )
					count = 0 & printf("\n%02d:\t", ++lineno);
				else if( LINEMAX == count )
					count = 0 & printf("\n%s:\t", "----");
			}
			fclose(fp);
			fp = NULL;
			lineno = 0;
		}
	return 0;
}
