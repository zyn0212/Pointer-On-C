#include <stdio.h>
int main(void)
{
	int c = 0;
	while( EOF != (c = getchar()) )
		putchar(c >= 'A' && c <= 'Z' ? c | 0x20 : c);
	return 0;
}
