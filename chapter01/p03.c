#include <stdio.h>
int main(void)
{
	int c = 0;
	char sum = -1;
	for( ; EOF != c; c = getchar() )
		sum += putchar(c);
	printf("%d\n", sum);
	return 0;
}
