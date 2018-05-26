#include <stdio.h>
#ifdef MAKENUM
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
	srand(time(0));
	if( 2 != argc )
		return 0 & printf("no outputfile or more than one outputfile!\n");
	FILE *fp = fopen(argv[1], "w");
	if( NULL == fp )
		return 0 & printf("open file : %s failed!\n", argv[1]);
	int line = (rand() & 0x3F) + 1, number = 0;
	int i = 0, j = 0;
	for( i = 0; i < line; ++i, fprintf(fp, "\n") )
		for( j = 0; j < (rand() & 0xF) + 1; ++j, fputc(' ', fp) )
			fprintf(fp, "%02d", rand() % 99 + 1);
	fclose(fp);
	fp = NULL;
	return 0;
}
#else
#define LINEMAX 100
#include <string.h>
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return 0 & printf("No input file or too many inputfile!\n");
	char Result[LINEMAX];
	memset(Result, 0, sizeof Result);
	char *pc = Result + 6;
	int tmp = 0, total = 0, c = 0, number = 0, len = 0, last = 0;
	FILE *fp = fopen(argv[1], "r");
	if(NULL == fp )
		return 0 & printf("open inputfile %s failed!\n", argv[1]);
	while( NULL != fgets(pc, LINEMAX - 6, fp) ) {
		len = strlen(pc);
		if( '\n' != *(pc + len - 1) ) {
			while( '\n' != fgetc(fp) )
				NULL;
			continue;
		}
		while( '\n' != (c = *pc++) ) {
			if( c >= '0' && c <= '9' )
				tmp = tmp * 10 + c - '0';
			else {
				if( last >= '0' && last <= '9' && (' ' == c || '\t' == c) )
					number += 1, total += tmp;
				tmp = 0;
			}
			last = c;
		}
		c = Result[6];
		sprintf(Result, "%5.2f:", (float)total / number);
		Result[6] = c;
		printf("%s\n", Result);
		memset(Result, 0, sizeof Result);
		pc = Result + 6;
		number = 0, total = 0;
	}
	if( strlen(pc) > 0 ) {
		while( '\n' != (c = *pc++) && EOF != c ) {
			if( c >= '0' && c <= '9' )
				tmp = tmp * 10 + c - '0';
			else {
				if( last >= '0' && last <= '9' && (' ' == c || '\t' == c) )
					number += 1, total += tmp;
				tmp = 0;
			}
			last = c;
		}
		c = Result[6];
		sprintf(Result, "%5.2f:", (float)total / number);
		Result[6] = c;
		printf("last line:%s\n", Result);
	}
	fclose(fp);
	fp = NULL;
	return 0;
}
#endif
