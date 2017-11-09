#include <stdio.h>
static unsigned int reverse_bits(unsigned int n);
int main(void)
{
	unsigned int n = 25;
	printf("%u\n", reverse_bits(n));
	return 0;
}
static unsigned int reverse_bits(unsigned int n)
{
	int *s = NULL, i = 0;
	unsigned int result = 0;
	for( i = 0; i < (sizeof s << 3); ++i )
		result |= (1 << i & n) >> i << (sizeof s << 3) - 1 - i;
	return result;
}
