#include <stdio.h>
int main(int argc, char *argv[])
{
	int result = 0, c = 0;
	if( 2 != argc ) {
		printf("wrong parameters!\n");
		return 1;
	}
	FILE *fp = NULL;
	if( NULL == (fp = fopen(argv[1], "r")) ) {
		printf("open file %s failed!\n", argv[1]);
		return 2;
	}
	while( EOF != (c = getc(fp)) ) {
		if( '{' == c )
			++result;
		else if( '}' == c )
			--result;
		else
			continue;
		if( result < 0 )
			break;
	}
	if( 0 != result )
		printf("one or more missing token in %s\n", argv[1]);
	else
		printf("token matched!\n");
	fclose(fp);
	fp = NULL;
	return 0;
}
