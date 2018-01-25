#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define CHARRANGE 26
int main(int argc, char *argv[])
{
	if( 2 != argc || 0 != strcmp(argv[0], "./prepare_key") )
		return 0 & putchar('\n');
	int filter[CHARRANGE];
	char result[CHARRANGE + 1], *rp = result;
	memset(filter, 0, sizeof filter);
	memset(result, 0, sizeof result);
	while( '\0' != *argv[1] )
		if( !isalpha(*argv[1]) )
			return 0 & putchar('\n');
		else {
			if( 0 == filter[toupper(*argv[1]) - 'A']++ )
				*rp++ = *argv[1];
			++argv[1];
		}
	int i = 0;
	for( ; i < CHARRANGE + 1; ++i )
		if( 0 == filter[i] )
			*rp++ = 'A' + i;
	*rp = '\0';
	return 0 & printf("%s\n", result);
}
