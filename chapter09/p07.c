#include <stdio.h>
#define MAX 32
static char *my_strrchr(char const *str, int ch);
int main(void)
{
	char ss[MAX] = "wo ai sun lina!";
	printf("%s\n", my_strrchr(ss, 'n'));
	return 0;
}
static char *my_strrchr(char const *str, int ch)
{
	char const *ret = NULL;
	while( '\0' != *str ) {
		if( *str == ch )
			ret = str;
		++str;
	}
	return (char *)ret;
}
