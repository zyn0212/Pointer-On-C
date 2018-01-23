#include <stdio.h>
#define MAX 32
static char *my_strcpy(char *des, char const *src, int maxsize);
int main(void)
{
	char des[MAX] = "";
	printf("%s\n", my_strcpy(des, "ashshhdfh", 5));
	return 0;
}
static char *my_strcpy(char *des, char const *src, int maxsize)
{
	if( NULL == des || NULL == src || maxsize < 0 )
		return NULL;
	char *ret_des = des;
	for( ; maxsize >= 0 && '\0' != (*des++ = *src++); --maxsize )
		continue;
	if( maxsize < 0 )
		*--des = '\0';
	return ret_des;
}
