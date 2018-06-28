#include <stdio.h>
#include <stdlib.h>
#include "p02_queue.h"
#include <time.h>
int main(void)
{
	srand(time(NULL));
	int size = 20, i = 0;
	create_queue(size);
	for( ; i < 5; ++i )
		insert(i);
	for( i = 0; i < 5; ++i )
		first();
	for( i = 0; i < size - 2; ++i )
		insert(i);
	for( i = 0; i < size - 2; ++i )
		printf("%d%c", first(), 0 == (i + 1 & 0xF) ? '\n' : '\t');
	putchar('\n');
	destroy_queue();
	return 0;
}
