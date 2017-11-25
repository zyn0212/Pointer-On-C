#include <stdio.h>
#include <string.h>
#define MAX 100
static int del_substr(char *str, char const *substr);
int main(int argc, char *argv[])
{
	if( 3 != argc ) {
		printf("Wrong parameter!\n");
		return 0;
	}
	int i = 0;
	char tmp[MAX], *p = NULL;
	memset(tmp, 0, sizeof tmp);
	p = tmp;
	while( i < MAX && (*p++ = *argv[1]++) )
		++i;
	if( MAX == i )
		*p = '\0';
	if( 1 == del_substr(tmp, argv[2]) )
		printf("%s\n", tmp);
	return 0;
}
static int del_substr(char *str, char const *substr)
{
	if( NULL == str || NULL == substr )
		return 0;
	char *sp = NULL;
	char const *ssp = NULL;
	while( '\0' != *str && strlen(str) >= strlen(substr) ) {
		sp = str;
		ssp = substr;
		//judge
		while( '\0' != *ssp && *sp++ == *ssp++ )
			continue;
		if( '\0' == *ssp )
			return sprintf(str, "%s", sp), 1;
		++str;
	}
	return 0;
}
