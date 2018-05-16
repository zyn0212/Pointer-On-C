#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NAMELENGTH 20
typedef struct node_tag {
	int value;
	char name[NAMELENGTH + 1];
	struct node_tag *prev;
	struct node_tag *next;
} NODE;
static int RemoveNode(NODE ** const base, NODE * const node, int ishead);
static void MakeNode(NODE * const node);
static void PrintNode(NODE * const node, int ishead, int needfree);
int main(void)
{
	srand(time(0));
	NODE * const head = (NODE *)malloc(sizeof(NODE));
	if( NULL == head )
		return 0 & printf("malloc got fatal error!\n");
	memset(head, 0, sizeof(NODE));
	head->prev = NULL;
	head->next = NULL;
	MakeNode(head);
	NODE *current = head, *last = NULL;
	int i = 0;
	for( i = 0; i < 10 - 1; ++i ) {
		current->next = (NODE *)malloc(sizeof(NODE));
		last = current;
		current = current->next;
		if( NULL == current )
			return 0 & printf("malloc got fatal error!\n");
		memset(current, 0, sizeof(NODE));
		last->next = current;
		current->prev = last;
		MakeNode(current);
	}
	current->next = NULL;
	NODE * const tail = current;
	current = head;
	PrintNode(head, 1, 0);
	PrintNode(tail, 0, 0);
	NODE *todel = (NODE *)malloc(sizeof(NODE));
	todel->value = 1;
	if( NULL == todel )
		printf("malloc got fatal error!\n");
	else if( RemoveNode(&head, todel, 0) )
		printf("node deleted!\n");
	else
		printf("node missed!\n");
	PrintNode(head, 1, 0);
	PrintNode(tail, 0, 1);
	free(todel);
	return 0;
}
static int RemoveNode(NODE ** const base, NODE * const node, int ishead)
{
	int NodeCmp(NODE * const a, NODE * const b);
	if( NULL == base || NULL == node )
		return 0;
	NODE * current = *base;
	while( NULL != current ) {
		if( NodeCmp(current, node) ) {
			if( *base == current )
				*base = current->next;
			else
				current->prev->next = current->next;
			if( NULL == current->next )
				current->prev->next = NULL;
			else
				current->next->prev = current->prev;
			return 1;
		}
		if( ishead )
			current = current->next;
		else
			current = current->prev;
	}
	return 0;
}
static void MakeNode(NODE * const node)
{
	static int number = 1;
	int i = 0;
	node->value = number++;
	char *cp = node->name;
	for( i = 0; i < NAMELENGTH; ++i )
		node->name[i] = rand() % 26 + 0x61;
	node->name[i] = '\0';
	return;
}
static void PrintNode(NODE * const node, int ishead, int needfree)
{
	if( NULL == node )
		return;
	NODE * current = node, *last = NULL;
	while( NULL != current ) {
		printf("%d\t%s\n", current->value, current->name);
		last = current;
		if( ishead )
			current = current->next;
		else
			current = current->prev;
		if( needfree )
			free(last);
	}
	return;
}
int NodeCmp(NODE * const a, NODE * const b)
{
	return a->value == b->value;
}
