#include <stdio.h>
static int getResult(int a, int b, int c);
int main(void)
{
	int a = 0, b = 0, c = 0, max = 0, min = 0;
	while( 1 ) {
		while( 3 == scanf("%d,%d,%d", &a, &b, &c) ) {
			while( '\n' != getchar() )
				continue;
			max = a > b ? a : b;
			max = max > c ? max : c;
			min = a < b ? a : b;
			min = min < c ? min : c;
			b ^= a ^ c;
			a = max;
			c = min;
			b ^= a ^ c;
			if( 0 == a && 0 == b && 0 == c )
				return 0;
			switch( getResult(a, b, c) ) {
				case 0:
					printf("deng bian sanjianxing\n");
					break;
				case 1:
					printf("deng yao sanjiaoxing\n");
					break;
				case 2:
					printf("deng yao zhijiao sanjiaoxing\n");
					break;
				case 3:
					printf("zhijiao sanjiaoxing\n");
					break;
				case 4:
					printf("sanjiaoxing\n");
					break;
				default:
					printf("out of range!\n");
					break;
			}
		}
		while( '\n' != getchar() )
			continue;
	}
	return 0;
}
static int getResult(int a, int b, int c)
{
	if( a >= b + c )
		return -1;
	else if( a == b && b == c )
		return 0;
	else if( b == c ) {
		if( a * a == b * b + c * c )
			return 2;
		else
			return 1;
	}
	else if( a * a == b * b + c * c )
		return 3;
	else
		return 4;
}
