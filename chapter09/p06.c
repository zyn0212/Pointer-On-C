#include <stdio.h>
#define MAX 12
static char *my_strcpy_end(char *dest, char const *src, int maxsize);
int main(void)
{
	char dest[MAX] = "wo aini sun!";
	printf("%s\t= %ld\n", dest, my_strcpy_end(dest, "yisheng yishi", MAX) - dest);
	return 0;
}
static char *my_strcpy_end(char *dest, char const *src, int maxsize)
{
	for( ; maxsize > 0 && '\0' != (*dest++ = *src++); --maxsize )
		continue;
	if( 0 == maxsize ) {
		*--dest = '\0';
		return dest;
	}
	return --dest;
}
