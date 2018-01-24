#include <stdio.h>
#define MAX 256
static int count_chars(char const *str, char const *chars);
static void initcharset(char const *chars);
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 0 & printf("Wrong parameters!\n");
	initcharset(argv[2]);
	printf("%d\n", count_chars(argv[1], argv[2]));
	return 0;
}
char charset[MAX];
static int count_chars(char const *str, char const *chars)
{
	int ret_value = 0;
	while( '\0' != *str )
		ret_value += charset[*str++];
	return ret_value;
}
static void initcharset(char const *chars)
{
	while( '\0' != *chars )
		charset[*chars++] = 1;
	return;
}
