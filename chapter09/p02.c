#include <stdio.h>
#include <string.h>
#define MAX 20
static int my_strlen(char *s, int const maxsize);
int main(int argc, char *argv[])
{
	char des[MAX] = "\0";
	strcpy(des, argv[1]);
	printf("%d\n", my_strlen(des, MAX));
	return 0;
}
static int my_strlen(char *s, int const maxsize)
{
	int i = 0;
	for( i = 0; i < maxsize; ++i )
		if( '\0' == s[i] )
			break;
	return i;
}
