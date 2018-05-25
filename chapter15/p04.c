#include <stdio.h>
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 0 & printf("Usage: command inputfile outputfile!\tTry again!\n");
	FILE *fpi = NULL, *fpo = NULL;
	fpi = fopen(argv[1], "r");
	if( NULL == fpi )
		return 0 & printf("Error:open inputfile:%s failed!\n", argv[1]);
	fpo = fopen(argv[2], "w");
	if( NULL == fpo ) {
		fclose(fpi);
		fpi = NULL;
		return 0 & printf("Error:open outputfile:%s failed!\n", argv[2]);
	}
	int c = 0;
	do {
		c = fgetc(fpi);
		fputc(c, fpo);
	} while( EOF != c );
	fflush(fpo);
	fclose(fpi);
	fpi = NULL;
	fclose(fpo);
	fpi = NULL;
	printf("copy file from %s to %s successed!\n", argv[1], argv[2]);
	return 0;
}
