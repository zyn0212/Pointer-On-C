#include <stdio.h>
#define MAX 64
int format(char *format_string, char const *digit_string);
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 0 & printf("Wrong parameters!\n");
	char result[MAX];
	char *result_p = result;
	while( *result_p++ = *argv[1]++ )
		NULL;
	if( 1 == format(result, argv[2]) )
		printf("format string:%s\n", result);
	else
		printf("format digit string error!\n");
	return 0;
}
int format(char *format_string, char const *digit_string)
{
	if( NULL == format_string || NULL == digit_string )
		return 0;
	int format_len = 0, digit_len = 0, i = 0;
	char ispoint = 0;
	while( '\0' != format_string[format_len] ) {
		if( '.' == format_string[format_len] )
			ispoint = 1;
		++format_len;
	}
	while( '\0' != digit_string[digit_len] )
		++digit_len;
	if( digit_len > format_len )
		return 0;
	for( i = format_len; i >= 0; --i, --digit_len )
		switch( format_string[i] ) {
			case '#':
				if( digit_len >= 0 )
					format_string[i] = digit_string[digit_len];
				else if( 1 == ispoint )
					format_string[i] = '0';
				else
					format_string[i] = ' ';
				break;
			case ',':
				if( digit_len >= 0 )
					format_string[i] = ',', ++digit_len;
				break;
			case '.':
				format_string[i--] = '.';
				ispoint = 0;
				if( '#' == format_string[i] )
					format_string[i] = digit_len >= 0 ? digit_string[digit_len] : '0';
				else
					++i, ++digit_len;
				break;
			case '\0':
				format_string[i] = '\0';
				break;
			default:
				return 0;
		}
	return 1;
}
