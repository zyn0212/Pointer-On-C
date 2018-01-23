#include <stdio.h>
#define MAX 32
static void my_strncat(char *dest, char const *src, int dest_len);
int main(void)
{
	char dest1[MAX] = "nihao";
	char dest2[MAX] = "nihao";
	char dest3[MAX] = "nihao";
	char dest4[MAX] = "nihao";
	char dest5[MAX] = "nihao";
	my_strncat(dest1, ", sunlina", 2);
	printf("%s\n", dest1);
	my_strncat(dest2, ", sunlina", 5);
	printf("%s\n", dest2);
	my_strncat(dest3, ", sunlina", 8);
	printf("%s\n", dest3);
	my_strncat(dest4, ", sunlina", 10);
	printf("%s\n", dest4);
	my_strncat(dest5, ", sunlina", 20);
	printf("%s\n", dest5);
	return 0;
}
static void my_strncat(char *dest, char const *src, int dest_len)
{
	for( ; dest_len > 0 && '\0' != *dest; --dest_len )
		++dest;
	for( ; dest_len > 0 && '\0' != (*dest++ = *src++); --dest_len )
		continue;
	if( 0 == dest_len )
		*dest = '\0';
	return;
}
