#include <stdio.h>
#include <string.h>
#define MAX 129
int main(int argc, char *argv[])
{
	if( 2 != argc ) {
		printf("wrong parameters!\n");
		return 1;
	}
	FILE *fp = NULL;
	if( NULL == (fp = fopen(argv[1], "r")) ) {
		printf("open file %s failed!\n", argv[1]);
		return 2;
	}
	char base[MAX];
	char *bp = base + 1;
	int c = 0;
	char flag = 1;
	memset(base, 0, sizeof base);
	while( EOF != (c = getc(fp)) ) {
		if( 1 == flag && *bp == c )
			;
		else {
			*bp = c;
			flag = 0;
		}
		if( '\n' == c ) {
			*++bp = '\0';
			if( 1 == flag )
				*base += 1;
			else
				*base = 0;
			flag = 1;
			bp = base + 1;
			if( 1 == *base )
				printf("%s", base + 1);
		}
		else
			++bp;
	}

	fclose(fp);
	fp = NULL;
	return 0;
}
