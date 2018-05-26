#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRINGMAX 110
static void fgrep(char const * const string, char const * const filename);
int main(int argc, char *argv[])
{
	if( 1 == argc )
		return 0 & printf("try with --help!\n");
	else if( 2 == argc && 0 == strcmp(argv[1], "--help") )
		return 0 & printf("Usage: command string inputfile\nSearch string in inputfile or input from keyboard if no inputfile!\n");
	else if( 2 == argc )
		fgrep(argv[1], NULL);
	else
		while( --argc > 1 )
			fgrep(argv[1], argv[argc]);
	return 0;
}
static void fgrep(char const * const string, char const * const filename)
{
	if( NULL == string || '\0' == *string ) {
		printf("input a empty string!\n");
		exit(0);
	}
	int line = 1, c = 0;
	char const *pc = string;
	char tmp[STRINGMAX];
	char *pct = tmp;
	memset(tmp, 0, sizeof tmp);
	FILE *fp = NULL;
	if( NULL == filename )
		fp = stdin;
	else {
		if( NULL == (fp = fopen(filename, "r")) ) {
			printf("open file: %s failed!\n", filename);
			return;
		}
	}
	while( EOF != (c = fgetc(fp)) ) {
		*pct++ = c;
		if( c == *pc ) {
			pc += 1;
			if( '\0' == *pc ) {
				printf("%s:%s", NULL == filename ? "Keyboard" : filename, tmp);
				while( EOF != (c = fgetc(fp)) && '\n' != c )
					putchar(c);
				if( EOF == c )
					return;
				putchar('\n');
				line += 1;
				memset(tmp, 0, sizeof tmp);
				pct = tmp, pc = string;
			}
		}
		else
			pc = string;
		if( '\n' == c ) {
			line += 1;
			memset(tmp, 0, sizeof tmp);
			pct = tmp, pc = string;
		}
	}
	fclose(fp);
	fp = NULL;
	return;
}
