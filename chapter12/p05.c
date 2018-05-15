#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct node_tag {
	int value;
	struct node_tag *next;
} NODE;
static int RemoveNode(NODE **rootp, NODE *node);
int main(void)
{
	srand(time(0));
	NODE * const head = (NODE *)malloc(sizeof(NODE));
	if( NULL == head )
		return 0 & printf("malloc got fatal error!\n");
	memset(head, 0, sizeof(NODE));
	head->value = rand() & 0x7F;
	NODE *current = head;
	int i = 0;
	for( i = 0; i < 30; ++i ) {
		current->next = (NODE *)malloc(sizeof(NODE));
		current = current->next;
		if( NULL == current )
			return 0 & printf("malloc got fatal error!\n");
		memset(current, 0, sizeof(NODE));
		current->value = rand() & 0x7F;
	}
	current->next = NULL;
	current = head;
	i = 0;
	while( NULL != current ) {
		printf("%03d%c", current->value, (++i & 15) == 0 ? '\n' : '\t');
		current = current->next;
	}
	if( 0 != (i & 7) )
		putchar('\n');
	NODE tmp;
	tmp.value = 33;
	if( 0 == RemoveNode(&head, &tmp) )
		printf("Node is missed!\n");
	current = head;
	i = 0;
	while( NULL != current ) {
		printf("%03d%c", current->value, (++i & 15) == 0 ? '\n' : '\t');
		current = current->next;
	}
	if( 0 != (i & 7) )
		putchar('\n');
	return 0;
}
static int RemoveNode(NODE **rootp, NODE *node)
{
	if( NULL == rootp || NULL == node )
		return -1;
	int NodeCmp(NODE *a, NODE *b);
	NODE *current = *rootp;
	if( 1 == NodeCmp(current, node) ) {
		*rootp = current->next;
		current->next = NULL;
		return 1;
	}
	else {
		NODE *last = current;
		current = current->next;
		while( NULL != current ) {
			if( 1 == NodeCmp(current, node) ) {
				last->next = current->next;
				current->next = NULL;
				return 1;
			}
			last = current;
			current = current->next;
		}
	}
	return 0;
}
int NodeCmp(NODE *a, NODE *b)
{
	return a->value == b->value ? 1 : 0;
}
