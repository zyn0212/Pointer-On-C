#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NAMELENGTH 21
typedef struct node_tag {
	int value;
	char PlayName[NAMELENGTH];
	int str;
	int dex;
} NODE;
int ia[NAMELENGTH];
static int MergeSort(void *start, size_t size, int n, int (*cmp)(void *, void *));
static int intcmp(void *a, void *b);
static void swap(void *a, void *b, size_t size);
int main(void)
{
	srand(time(0));
	int i = 0;
	memset(ia, 0, sizeof ia);
	for( i = 0; i < NAMELENGTH; ++i )
		ia[i] = rand() & 0x7F;
	for( i = 0; i < NAMELENGTH; ++i )
		printf("%d\t%d\n", i, ia[i]);
	printf("=======================\n");
	MergeSort(ia, sizeof ia[0], NAMELENGTH, intcmp);
	for( i = 0; i < NAMELENGTH; ++i )
		printf("%d\t%d\n", i, ia[i]);
	return 0;
}
static void Merging(void *head, size_t size, int n, int (*cmp)(void *, void *), void *sorted);
static int MergeSort(void *start, size_t size, int n, int (*cmp)(void *, void *))
{
	if( NULL == start || size < 1 || n < 2 || NULL == cmp )
		return -1;
	void * const sorted = (void *)calloc(n, size);
	if( NULL == sorted ) {
		printf("malloc got fatal error!\n");
		return -1;
	}
	if( n > 2 ) {
		MergeSort(start, size, n >> 1, cmp);
		MergeSort(start + (n >> 1) * size, size, n - (n >> 1), cmp);
		Merging(start, size, n, cmp, sorted);
	}
	else {
		if( (*cmp)(start, start + size) > 0 )
			swap(start, start + size, size);
	}
	return 0;
}
static void Merging(void *start, size_t size, int n, int (*cmp)(void *, void *), void *sorted)
{
	int i = 0, cmpvalue = 0;
	char *mid = start + (n >> 1) * size, *end = start + n * size;
	char *tail = mid, *head = start, *to = (char *)sorted;
	for( i = 0; i < n; ++i ) {
		if( head >= mid ) {
			memcpy(to, tail, size);
			tail += size;
		}
		else if( tail >= end ) {
			memcpy(to, head, size);
			head += size;
		}
		else if( (cmpvalue = (*cmp)(head, tail)) <= 0 ) {
			memcpy(to, head, size);
			head += size;
		}
		else {
			memcpy(to, tail, size);
			tail += size;
		}
		to += size;
	}
	memcpy(start, sorted, n * size);
	free(sorted);
	return;
}
static int intcmp(void *a, void *b)
{
	if( NULL == a && NULL == b )
		return 0;
	else if( NULL == a )
		return -1;
	else if( NULL == b )
		return 1;
	else
		return *(int *)a > *(int *)b ? 1 : *(int *)a == *(int *)b ? 0 : -1;
}
static void swap(void *a, void *b, size_t size)
{
	int i = 0;
	char *ca = (char *)a, *cb = (char *)b;
	for( i = 0; i < size; ++i, ca += 1, cb += 1 )
		*ca ^= *cb ^= *ca ^= *cb;
	return;
}
