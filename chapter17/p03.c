#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "p02_queue.h"
#define MAX 30
int main(void)
{
	srand(time(0));
	int i = 0;
	create_queue(MAX + 100);
	for( i = 0; i < MAX; ++i )
		insert(i);
	resize(MAX + 20);
	for( i = 0; i < MAX; ++i )
		printf("%d%c", first(), 0 == (i + 1 & 0xF) ? '\n' : '\t');
	putchar('\n');
	destroy_queue();
	return 0;
}
