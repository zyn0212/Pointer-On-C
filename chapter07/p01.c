#include <stdio.h>
#include <stdlib.h>
int hermite(int n, int x);
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 0 & printf("wrong parameters!\n");
	int n = atoi(argv[1]), x = atoi(argv[2]);
	printf("%d\n", hermite(n, x));
	return 0;
}
int hermite(int n, int x)
{
	if( n <= 0 )
		return 1;
	else if( 1 == n )
		return x << 1;
	else
		return (x << 1) * hermite( n - 1, x) - ((n - 1) << 1) * hermite(n - 2, x);
	return 0;
}
