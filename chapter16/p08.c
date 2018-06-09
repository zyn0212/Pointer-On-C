#include <string.h>
#include <stdio.h>
static int getAverage(FILE *fp);
int main(int argc, char *argv[])
{
	printf("----The average of age---\n");
	while( argc > 0 ) {
		FILE *fp = NULL == argv[argc] ? stdin : fopen(argv[argc], "r");
		if( NULL == fp )
			continue;
		while( getAverage(fp) > 0 )
			NULL;
		--argc;
		if( stdin != fp )
			fclose(fp);
		fp = NULL;
	}
	printf("----END------------------\n");
	return 0;
}
static int getAverage(FILE *fp)
{
	int count = 0, sum = 0, c = 0, tmp = 0, head = 0;
	do {
		c = fgetc(fp);
		if( c >= '0' && c <= '9' )
			tmp = tmp * 10 + c - '0';
		else if( tmp > 0 && tmp < 200 ) {
			++count;
			sum += tmp;
			printf("%s%d", 0 == head++ ? "       " : " ", tmp);
			tmp = 0;
		}
		else
			tmp = 0;
	} while( ' ' == c || '\t' == c || (c >= '0' && c <= '9') );
	while( '\n' != c && EOF != c )
		c = fgetc(fp);
	if( count > 0 )
		printf("\r%5.2f:\n", (float)sum / count);
	return count;
}
