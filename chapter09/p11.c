#include <stdio.h>
#include <ctype.h>
static int count_the(char const *string);
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return 0 & printf("Wrong parameter!\n");
	int result = count_the(argv[1]);
	printf("There %s %d \"the\" in your input!\n", result < 2 ? "was" : "were", result);
	return 0;
}
static int count_the(char const *string)
{
	int ret_value = 0, bit = 0;
	while( '\0' != *string ) {
		if( 0 == bit && isspace(*string) )
			++bit;
		else if( 1 == bit && 't' == *string )
			++bit;
		else if( 2 == bit && 'h' == *string )
			++bit;
		else if( 3 == bit && 'e' == *string )
			++bit;
		else if( 4 == bit && isspace(*string) ) {
			bit = 0;
			++ret_value;
		}
		else
			bit = 0;
		++string;
	}
	if( 4 == bit )
		++ret_value;
	return ret_value;
}
