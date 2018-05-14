#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tag {
	int value;
	struct tag *next;
} NODE;
static NODE * RevertNode(NODE * const head);
int main(void)
{
	NODE * const head = (NODE *)malloc(sizeof(NODE));
	if( NULL == head )
		return 0 & printf("malloc got fatal error!\n");
	memset(head, 0, sizeof(NODE));
	head->value = 3;
	int i = 0;
	NODE * current = head;
	for( i = 2; i < 40; ++i ) {
		current->next = (NODE *)malloc(sizeof(NODE));
		current = current->next;
		if( NULL == current )
			return 0 & printf("malloc got fatal error!\n");
		memset(current, 0, sizeof(NODE));
		current->value = (i << 1) + 1;
	}
	current->next = NULL;
	current = head;
	while( NULL != current ) {
		printf("%02d\t", current->value);
		current = current->next;
	}
	putchar('\n');
	current = RevertNode(head);
	while( NULL != current ) {
		printf("%02d\t", current->value);
		current = current->next;
	}
	putchar('\n');
	return 0;
}
static NODE * RevertNode(NODE * const head)
{
	if( NULL == head || NULL == head->next )
		return NULL;
	NODE * last = head;
	NODE * current = head->next;
	last->next = NULL;
	NODE * tmp = NULL;
	while( NULL != current ) {
		tmp = current->next;
		current->next = last;
		last = current;
		current = tmp;
	}
	return last;
}
