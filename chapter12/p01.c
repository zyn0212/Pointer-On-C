#include <stdio.h>
#include <stdlib.h>
typedef struct tag {
	int value;
	struct tag * next;
} TAG;
static int ElementCount(TAG * element);
int main(void)
{
	TAG * const head = (TAG *)malloc(sizeof(TAG));
	if( NULL == head )
		return 0 & printf("malloc got fatal error!\n");
	int i = 0;
	TAG * loop = head;
	for( i = 5; i < 50; ++i ) {
		loop->value = i << 1;
		loop->next = (TAG *)malloc(sizeof(TAG));
		loop = loop->next;
		if( NULL == loop )
			return 0 & printf("malloc got fatal error!\n");
	}
	loop->next = NULL;
	printf("%d\n", ElementCount(head));
	loop = head;
	TAG * forfree = NULL;
	while( NULL != loop ) {
		forfree = loop;
		loop = loop->next;
		free(forfree);
	}
	return 0;
}
int ElementCount(TAG * element)
{
	if( NULL == element )
		return 0;
	int retvalue = 0;
	while( NULL != element ) {
		++retvalue;
		// lookup a value in it
		element = element->next;
	}
	return retvalue;
}
