#include <stdio.h>
#define MAX 64
static char *my_strnchr(char const *str, int ch, int which);
int main(void)
{
	char ss[MAX] = "aabbccddeeeeeeffgghhiijjkkllmmnnooppqqrrsstt";
	printf("%s\n", my_strnchr(ss, 'e', -1));
	return 0;
}
static char *my_strnchr(char const *str, int ch, int which)
{
	char const *ret = NULL;
	while( '\0' != *str ) {
		if( *str == ch ) {
			ret = str;
			if( 0 >= --which )
				break;
		}
		++str;
	}
	return (char *)ret;
}
