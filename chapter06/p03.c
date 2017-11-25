#include <stdio.h>
#include <string.h>
#define MAX 100
static void reverse_string(char *string);
int main(int argc, char *argv[])
{
	char tmp[MAX];
	memset(tmp, 0, sizeof tmp);
	if( 1 == argc ) {
		scanf("%s", tmp);
		reverse_string(tmp);
		printf("%s\n", tmp);
	}
	else {
		int i = 1;
		for( ; i < argc; ++i ) {
			reverse_string(argv[i]);
			printf("%s\n", argv[i]);
		}
	}
	return 0;
}
static void reverse_string(char *string)
{
	char *head = string, *tail = string + strlen(string) - 1;
	while( head < tail && *head != *tail ) {
		*head ^= *tail ^= *head ^= *tail;
		head++, tail--;
	}
	return;
}
