#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "p01_stack.h"
int main(void)
{
	srand(time(0));
	int size = 20, i = 0;
	create_stack(20);
	for( ; i < size; ++i )
		push(i);
	resize_stack(40);
	for( ; i < 40; ++i )
		push(i);
	for( i = 0; i < 40; ++i )
		printf("%d%c", pop(), 0 == (i + 1 & 0xF) ? '\n' : '\t');
	putchar('\n');
	destroy_stack();
	return 0;
}
