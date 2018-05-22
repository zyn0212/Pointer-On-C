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
typedef enum {
	LARGE_TO_SMALL = 1,
	SMALL_TO_LARGE = -1,
} SORT_TYPE;
static int MergeSort(void *start, size_t size, int n, int (*cmp)(void *, void *), SORT_TYPE sorttype);
static int nodecmp(void *a, void *b);
static void swap(void *a, void *b, size_t size);
int main(void)
{
	srand(time(0));
	int i = 0, j = 0;
	NODE ia[NAMELENGTH];
	char *cp = NULL;
	memset(ia, 0, sizeof ia);
	for( i = 0; i < NAMELENGTH; ++i ) {
		ia[i].value = i + 1;
		ia[i].str = rand() & 0x0F;
		ia[i].dex = rand() & 0x0F;
		for( j = 0, cp = ia[i].PlayName; j < NAMELENGTH - 1; ++j )
			*cp++ = rand() % 26 + 'a';
		*cp = '\0';
	}
	for( i = 0,printf("No\t%-21s\tSTR\tDEX\n", "        NAME"); i < NAMELENGTH; ++i )
		printf("%d\t%21s\t%d\t%d\n", ia[i].value, ia[i].PlayName, ia[i].str, ia[i].dex);
	printf("=======================\n");
	SORT_TYPE sorttype = SMALL_TO_LARGE;
	MergeSort(ia, sizeof ia[0], NAMELENGTH, nodecmp, sorttype);
	for( i = 0,printf("No\t%-21s\tSTR\tDEX\n", "        NAME"); i < NAMELENGTH; ++i )
		printf("%d\t%21s\t%d\t%d\n", ia[i].value, ia[i].PlayName, ia[i].str, ia[i].dex);
	return 0;
}
static void Merging(void *head, size_t size, int n, int (*cmp)(void *, void *), void *sorted, SORT_TYPE sorttype);
static int MergeSort(void *start, size_t size, int n, int (*cmp)(void *, void *), SORT_TYPE sorttype)
{
	if( NULL == start || size < 1 || n < 2 || NULL == cmp )
		return -1;
	void * const sorted = (void *)calloc(n, size);
	if( NULL == sorted ) {
		printf("malloc got fatal error!\n");
		return -1;
	}
	if( n > 2 ) {
		MergeSort(start, size, n >> 1, cmp, sorttype);
		MergeSort(start + (n >> 1) * size, size, n - (n >> 1), cmp, sorttype);
		Merging(start, size, n, cmp, sorted, sorttype);
	}
	else {
		if( ((*cmp)(start, start + size) ^ sorttype) < 0 )
			swap(start, start + size, size);
	}
	return 0;
}
static void Merging(void *start, size_t size, int n, int (*cmp)(void *, void *), void *sorted, SORT_TYPE sorttype)
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
		else if( ((cmpvalue = (*cmp)(head, tail)) ^ sorttype)  >= 0 ) {
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
static int nodecmp(void *a, void *b)
{
	if( NULL == a && NULL == b )
		return 0;
	else if( NULL == a )
		return -1;
	else if( NULL == b )
		return 1;
	else
		return ((NODE *)a)->str > ((NODE *)b)->str ? 1 : ((NODE *)a)->str < ((NODE *)b)->str
															? -1 : ((NODE *)a)->dex > ((NODE *)b)->dex ? 1 : ((NODE *)a)->dex < ((NODE *)b)->dex 
																							? -1 : strcmp(((NODE *)a)->PlayName, ((NODE *)b)->PlayName);
}
static void swap(void *a, void *b, size_t size)
{
	int i = 0;
	char *ca = (char *)a, *cb = (char *)b;
	for( i = 0; i < size; ++i, ca += 1, cb += 1 )
		*ca ^= *cb ^= *ca ^= *cb;
	return;
}
