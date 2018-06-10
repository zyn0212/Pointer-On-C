#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ELEMENTMAX 30
typedef struct {
	int value;
	char cc;
	float ff;
} NODE;
static int nodecmp(void *a, void *b);
static int insertion_sort(void *start, int n, size_t size, int (*comp)(void *, void *));
int main(void)
{
	NODE base[ELEMENTMAX];
	memset(base, 0, sizeof base);
	int i = 0;
	srand(time(0));
	for( ; i < ELEMENTMAX; ++i ) {
		base[i].value = rand() & 0x7FFF;
		base[i].cc = rand() & 0x7F;
		base[i].ff = (rand() & 0x7F) / 10.0;
		printf("%10d, %3d, %5.2f\n", base[i].value, base[i].cc, base[i].ff);
	}
	insertion_sort(base, ELEMENTMAX, sizeof(NODE), nodecmp);
	printf("-----------Result after insertion sort---------------\n");
	for( i = 0; i < ELEMENTMAX; ++i ) 
		printf("%10d, %3d, %5.2f\n", base[i].value, base[i].cc, base[i].ff);
	return 0;
}
static int insertion_sort(void *start, int n, size_t size, int (*comp)(void *, void *))
{
	if( NULL == start || n < 2 || size < 1 || NULL == comp )
		return 0;
	char *tmp = (char *)calloc(1, size);
	if( NULL == tmp )
		return 0;
	int movetime = 0, i = 0, j = 0;
	for( i = 1; i < n; ++i ) {
		for( j = 0; j < i; ++j )
			if( comp(start + i * size, start + j * size) < 0 )
				break;
		if( j < i ) {
			memcpy(tmp, start + i * size, size);
			memmove(start + (j + 1) * size, start + j * size, (i - j) * size);
			memcpy(start + j * size, tmp, size);
		}
		memset(tmp, 0, size);
	}
	free(tmp);
	tmp = NULL;
	return movetime;
}
static int nodecmp(void *a, void *b)
{
#ifdef FF
	return ((NODE *)a)->ff == ((NODE *)b)->ff ? 0 : ((NODE *)a)->ff < ((NODE *)b)->ff ? -1 : 1;
#elif defined CC
	return ((NODE *)a)->cc == ((NODE *)b)->cc ? 0 : ((NODE *)a)->cc < ((NODE *)b)->cc ? -1 : 1;
#elif defined VV
	return ((NODE *)a)->value == ((NODE *)b)->value ? 0 : ((NODE *)a)->value < ((NODE *)b)->value ? -1 : 1;
#else
	return 0;
#endif
}
