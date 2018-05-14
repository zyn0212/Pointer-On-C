#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tag {
	int value;
	struct tag *next;
	struct tag *prev;
} NODE;
typedef enum {
	ASC,
	DESC,
} SORT_STATUS;
static int NODE_insert(NODE * const head, NODE * const tail, int value);
int main(void)
{
	NODE * const rootp = (NODE *)malloc(sizeof(NODE));
	NODE * current = NULL;
	NODE * last = NULL;
	if( NULL == rootp )
		return 0 & printf("malloc got fatal error!\n");
	memset( rootp, 0, sizeof(NODE));
	rootp->prev = NULL;
	int i = 10;
	rootp->value = i;
	for( i = 6, current = rootp; i < 20; ++i ) {
		last = current;
		current->next = (NODE *)malloc(sizeof(NODE));
		current= current->next;
		current->prev = last;
		if( NULL == current )
			return 0 & printf("malloc got fatal error!\n");
		current->value = i << 1;
	}
	current->next = NULL;
	NODE * const tail = current;
	while( rootp != current ) {
		printf("%d\n", current->value);
		current = current->prev;
	}
	printf("%d\n------------------------------------\n", current->value);
	NODE_insert(rootp, tail, 25);
	while( NULL != current ) {
		printf("%d\n", current->value);
		current = current->next;
	}
	return 0;
}
static int NODE_insert(NODE * const head, NODE * const tail, int value)
{
	void SwapNode(NODE *a, NODE *b);
	NODE * newnode = (NODE *)malloc(sizeof(NODE));
	if( NULL == newnode )
		return -1;
	newnode->value = value;
	newnode->next = NULL;
	newnode->prev = NULL;
	SORT_STATUS sortstatus = head->value > tail->value ? DESC : ASC;
	if( DESC == sortstatus && value > head->value || ASC == sortstatus && value < head->value ) {
		SwapNode(head, newnode);
		head->next = newnode;
		newnode->prev = head;
	}
	else {
		NODE * current = NULL;
		NODE * lower = head, * upper = tail;
		while( lower <= tail )
			if( DESC == sortstatus && value > lower->value || ASC == sortstatus && value < lower->value ) {
				current = lower->prev;
				break;
			}
			else if( DESC == sortstatus && value < upper->value || ASC == sortstatus && value > upper->value ) {
				current = upper;
				break;
			}
			else
				lower = lower->next, upper = upper->prev;
		newnode->prev = current;
		newnode->next = current->next;
		current->next = newnode;
	}
	return 0;
}
void SwapNode(NODE *a, NODE *b)
{
	NODE tmp = *a;
	memcpy(a, b, sizeof(NODE));
	memcpy(b, &tmp, sizeof(NODE));
	return;
}
