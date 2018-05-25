#include <stdio.h>
#include <string.h>
#define NUMBERMAX 20
static int palindrome(int n);
int main(void)
{
	int n = 1, c = 0, taillen = 0;
	while( 1 ) {
		printf("input a number for check(input 0 to stop:");
		while( 1 != scanf("%d", &n) ){
			while( '\n' != getchar() )
				NULL;
			printf("input a number for check(input 0 to stop:");
		}
		while( '\n' != (c = getchar()) )
			if( '\t' != c && ' ' != c && '\n' != c )
				taillen += 1;
		if( taillen > 0 ) {
			taillen = 0;
			continue;
		}
		if( 0 == n )
			break;
		printf("%d is%s a palindrome!\n", n, palindrome(n) ? "" : " not");
	}
	return 0;
}
static int palindrome(int n)
{
	if( n < 10 && n > -10 )
		return 1;
	char tmp[NUMBERMAX];
	memset(tmp, 0, sizeof tmp);
	int length = sprintf(tmp, "%d", n);
	char *head = tmp, *tail = tmp + length - 1;
	if( n < 0 )
		head += 1;
	while( head <= tail )
		if( *head++ != *tail-- )
			return 0;
	return 1;
}
