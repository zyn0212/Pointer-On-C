#include <stdio.h>
#include <string.h>
#define CHARMAXNUM 256
static char *find_char( char const *source, char const *set);
int main(int argc, char *argv[])
{
	if( 3 != argc ) {
		printf("Wrong parameter!\n");
		return 0;
	}
	printf("%s\n", NULL != find_char(argv[1], argv[2]) ? "findout" : "miss");
	return 0;
}
static char *find_char( char const *source, char const *set)
{
	char tmp[CHARMAXNUM];
	int len = strlen(set), i = 0;
	memset(tmp, 0, sizeof tmp);
	for( ; i < len; ++i )
		*(tmp + *(set + i)) = 1;
	while( '\0' != *source ) {
		if( 1 == tmp[*source] )
		if( 1 == *(tmp + *source) )
			return (char *)source;
		++source;
	}
	return NULL;
}
