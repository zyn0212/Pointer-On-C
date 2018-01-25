#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CHARRANGE 26
void decrypt(char *data, char const *key);
int main(int argc, char *argv[])
{
	if( 2 != argc || 0 != strcmp(argv[0], "./decrypt") )
		return 0 & putchar('\n');
	char key[CHARRANGE], c = 0;
	memset(key, 0, sizeof key);
	int i = 0;
	for( c = getchar(); '\n' != c && i < CHARRANGE; ++i, c = getchar() )
		key[toupper(c) - 'A'] = 'A' + i;
	if( CHARRANGE != i || '\n' != c )
		return 0 & printf("got keys failed!\n");
	else
		while( '\0' != *argv[1] )
			decrypt(argv[1]++, key);
	putchar('\n');
	return 0;
}
void decrypt(char *data, char const *key)
{
	putchar(isalpha(*data) ? (*data & 0x20) | key[toupper(*data) - 'A'] : *data);
}
