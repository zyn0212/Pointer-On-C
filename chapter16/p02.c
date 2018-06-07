#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	srand(time(0));
	printf("%d\n", 1 + (rand() & 1) + (rand() & 1) + (rand() & 1) + (rand() & 1) + (rand() & 1));
	return 0;
}
