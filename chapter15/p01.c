#include <stdio.h>
int main(int argc, char *argv[])
{
	int c = 0;
	if( 1 == argc ) {
		while( EOF != (c = getchar()) )
			putchar(c);
		putchar('\n');
	}
	else
		while( --argc > 0 ) {
			FILE *fp = fopen(argv[argc], "r");
			if( NULL == fp )
				continue;
			while( EOF != (c = fgetc(fp)) )
				putchar(c);
			putchar('\n');
			fclose(fp);
			fp = NULL;
		}
	return 0;
}
