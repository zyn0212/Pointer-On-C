#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct TAG {
	int value;
	struct TAG *next;
} tag;
typedef enum {
	INVALID,
	SMALLER,
	EQUAL,
	LARGER,
} status;
tag *LookupInTag(tag *head, int value);
int main(void)
{
	srand(time(0));
	tag * const head = (tag *)malloc(sizeof(tag));
	if( NULL == head )
		return 0 &printf("malloc got fatal error!\n");
	head->value = 21;
	tag *loop = head;
	int i = 0;
	for( i = 20; i > 3; --i ) {
		loop->next = (tag *)malloc(sizeof(tag));
		loop = loop->next;
		if( NULL == loop )
			return 0 &printf("malloc got fatal error!\n");
		loop->value = i;
	}
	loop->next = NULL;
	loop = LookupInTag(head, 100);
	printf("%d\n", NULL == loop ? -1 : loop->value);
	loop = head;
	tag *forfree = NULL;
	while( NULL != loop ) {
		forfree = loop;
		loop = loop->next;
		free(forfree);
	}
	return 0;
}
static inline status getStatus(int a, int b);
tag *LookupInTag(tag *head, int value)
{
	if( NULL == head )
		return NULL;
	status s = getStatus(value, head->value);
	if( NULL != head->next && getStatus(head->value, head->next->value) == s )
		switch( s ) {
			case EQUAL:
				return head;
				break;
			default:
				printf("miss!\n");
				return NULL;
				break;
		}
	while( NULL != head ) {
		if( value == head->value )
			break;
		head = head->next;
	}
	return head;
}
static status getStatus(int a, int b)
{
	return a == b ? EQUAL :
					a > b ? LARGER : SMALLER;
}
