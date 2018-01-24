#include <stdio.h>
#include <string.h>
static int palinkrome(char const *string);
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return 0 & printf("Wrong parameters!\n");
	printf("%s is%spalinkrome!\n", argv[1], 1 == palinkrome(argv[1]) ? " " : " not ");
	return 0;
}
static int palinkrome(char const *string)
{
	char const *head = string;
	char const *tail = string + strlen(string) - 1;
	while( head < tail )
		if( *head++ != *tail-- )
			return 0;
	return 1;
}
