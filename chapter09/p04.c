#include <stdio.h>
#define MAX 32
char *my_strcat(char *des, char const *src, int maxsize);
int main(void)
{
	char des[MAX] = "wo ai sunlina";
	printf("%s\n", NULL == my_strcat(des, ",zhi ai", 21) ? "" : des);
	return 0;
}
char *my_strcat(char *des, char const *src, int maxsize)
{
	if( NULL == des || NULL == src || maxsize < 0 )
		return NULL;
	char *ret_des = des;
	for( ; maxsize >= 0 && '\0' != *des; ++des, --maxsize )
		continue;
	for( ; maxsize >= 0 && '\0' != (*des++ = *src++); --maxsize )
		continue;
	if( maxsize < 0 )
		*--des = '\0';
	return ret_des;
}
