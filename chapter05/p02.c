#include <stdio.h>
#define isc(x) ((x) >= 'A' && (x) <= 'Z' || (x) >= 'a' && (x) <= 'z')
int main(void)
{
	int c = 0;
	while( EOF != (c = getchar()) )
		putchar(isc(c) ? (0x60 & c) + ((0x1F & c) + 13) % 26 : c);
	return 0;
}
