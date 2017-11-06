#include <stdio.h>
static int isPrime(int n);
int main(void)
{
	int start = 1, end = 100, i = 0;
	start += 0 == (1 & start) ? 1 : 0;
	for( i = start; i < end; i += 2 )
		if( 0 == isPrime(i) )
			printf("%d\n", i);
	return 0;
}
static int isPrime(int n)
{
	int i = 3;
	for( i = 3; i <= n >> 1; i += 2 )
		if( 0 == n % i )
			break;
	if( i > n >> 1 )
		return 0;
	return 1;
}
