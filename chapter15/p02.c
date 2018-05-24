#include <stdio.h>
#include <string.h>
#define LINEMAX 80
int main(int argc, char *argv[])
{
	int c = 0;
	char tmp[LINEMAX];
	char *pc = tmp;
	int lineno = 0;
	if( 1 == argc ) {
		memset(tmp, 0, sizeof tmp);
		while( EOF != (c = getchar()) ) {
			*pc++ = c;
			if( '\n' == c ) {
				printf("%02d:\t%s", ++lineno, tmp);
				pc = tmp;
				memset(tmp, 0, sizeof tmp);
			}
			else if( pc == tmp + LINEMAX - 1 ) {
				*pc = '\0';
				printf("%02d:\t%s", ++lineno, tmp);
				pc = tmp;
				memset(tmp, 0, sizeof tmp);
			}
			else
				NULL;
		}
		if( '\0' != tmp[0] )
			printf("%s\n", tmp);
	}
	else
		while( --argc > 0 ) {
			printf("Deal with %s:\n", argv[argc]);
			FILE *fp = fopen(argv[argc], "r");
			memset(tmp, 0, sizeof tmp);
			if( NULL == fp )
				continue;
			while( EOF != (c = fgetc(fp)) ) {
				*pc++ = c;
				if( '\n' == c ) {
					printf("%02d:\t%s", ++lineno, tmp);
					pc = tmp;
					memset(tmp, 0, sizeof tmp);
				}
				else if( pc == tmp + LINEMAX - 1 ) {
					*pc = '\0';
					printf("%02d:\t%s", ++lineno, tmp);
					pc = tmp;
					memset(tmp, 0, sizeof tmp);
				}
				else
					NULL;
			}
			if( '\0' != tmp[0] )
				printf("%s\n", tmp);
			pc = tmp;
			lineno = 0;
			fclose(fp);
			fp = NULL;
		}
	return 0;
}
