#include <stdio.h>
#include <string.h>
#define MAX 64
static void dollars(char *dest, char const *src);
int main(void)
{
	char s[MAX] = "", result[MAX];
	int i = 0;
	long sum = 0;
	dollars(result, s);
	printf("%s\n", result);
	for( i = 1; i < 15; ++ i ) {
		sum = sum * 10 + i % 10;
		sprintf(s, "%ld", sum);
		dollars(result, s);
		printf("%s\n", result);
	}
	return 0;
}
static void dollars(char *dest, char const *src)
{
	if( NULL == src  || NULL == dest )
		return;
	int length = strlen(src);
	if( 0 == length )
		sprintf(dest, "$0.00");
	else if( length > 0 && length < 3 )
		sprintf(dest, "$%.*s%s", 4 - length, "0.0", src);
	else if( length < 30 ) {
		length -= 2;
		int length_left = length % 3;
		if( 0 != length_left ) {
			sprintf(dest, "$%.*s%c", length_left, src, ".,,,,,,,,,"[(length - 1) / 3]);
			src += length_left;
			length -= length_left;
		}
		else
			sprintf(dest, "$");
		for( ; length > 0; length -= 3, src += 3 )
			sprintf(dest, "%s%.3s%c", dest, src, ".,,,,,,,,,"[(length - 1) / 3]);
		sprintf(dest, "%s%s", dest, src);
	}
	else
		memset(dest, 0, sizeof(char) * strlen(dest));
	return;
}
