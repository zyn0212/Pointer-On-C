#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static unsigned int sum(char const * const filename);
int main(int argc, char *argv[])
{
	if( 1 == argc )
		printf("%u\n", sum(NULL));
	else if( 2 == argc ) {
		if( 0 == strcmp(argv[1], "-f") )
			return 0 & printf("-f illegal when reading standard input\n");
		else
			sum(argv[1]);
	}
	else {
		int i = 0;
		if( 0 == strcmp(argv[1], "-f") )
			++i;
		while( ++i < argc )
			sum(argv[i]);
	}
	return 0;
}
static unsigned int sum(char const * const filename)
{
	unsigned int retvalue = 0;
	int needclose = 0;
	FILE *fpi = NULL, *fpo = NULL;
	char *outfile = NULL;
	if( NULL == filename )
		fpi = stdin, fpo = stdout;
	else {
		needclose = 1;
		outfile = (char *)calloc(strlen(filename) + 1 + 4, sizeof(char));
		if( NULL == outfile )
			return 0 & printf("calloc failed!\n");
		sprintf(outfile, "%s%s", filename, ".cks");
		fpi = fopen(filename, "r");
		if( NULL == fpi )
			return 0 & printf("open file: %s failed!\n", filename);
		fpo = fopen(outfile, "w");
		if( NULL == fpo ) {
			fclose(fpi);
			fpi = NULL;
			return 0 & printf("open file: %s failed!\n", outfile);
		}
		int c = 0;
		while( EOF != (c = fgetc(fpi)) )
			retvalue += c;
		fprintf(fpo, "%u\n", retvalue);
		fflush(fpo);
	}
	if( 1 == needclose ) {
		free(outfile);
		outfile = NULL;
		fclose(fpi);
		fpi = NULL;
		fclose(fpo);
		fpo = NULL;
	}
	return retvalue;
}
