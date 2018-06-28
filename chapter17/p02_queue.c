/*
	Copyright:	zhaoyining
	File Name:	p02_queue.c
	Description:interface for queue
	Author:		zhaoyining
	Version:	0.0.0
	Data:		2018-06-24
	History:	2018-06-24 create
   */
#include "p02_queue.h"
static int queue_size = 0;
static int element_count = 0;
static int *queue_stack = NULL;
static int *queue_head = NULL;
static int *queue_tail = NULL;
static void roundptr(int **stack);
void create_queue(size_t size)
{
	assert( !(0 != queue_size) );
	queue_size = size;
	queue_stack = (int *)calloc(size, sizeof(int));
	assert(!(NULL == queue_stack));
	queue_head = queue_stack;
	queue_tail = queue_stack;
	return;
}
void destroy_queue(void)
{
	assert( !(queue_size <= 0) );
	queue_size = 0;
	free(queue_stack);
	queue_stack = NULL;
	queue_head = NULL;
	queue_tail = NULL;
	return;
}
void insert(int value)
{
	assert(!is_full());
	*queue_tail++ = value;
	roundptr(&queue_tail);
	++element_count;
	return;
}
void delete(void)
{
	assert(!is_empty());
	first();
	return;
}
int first(void)
{
	assert( !is_empty() );
	int retvalue = *queue_head++;
	roundptr(&queue_head);
	--element_count;
	return retvalue;
}
int is_full(void)
{
	assert( !(queue_size <= 0) );
	return element_count == queue_size - 1;
}
int is_empty(void)
{
	assert( !(queue_size <= 0) );
	return element_count == 0;
}
void resize(size_t size)
{
	if( size < 1 || size == queue_size )
		return;
	int *res = (int *)realloc(queue_stack, size * sizeof(int));
	assert( !(NULL == res) );
	queue_size = size;
	queue_head = queue_head - queue_stack + res;
	queue_tail = queue_tail - queue_stack + res;
	queue_stack = res;
}
static void roundptr(int **stack)
{
	if( *stack >= queue_stack + queue_size )
		*stack = queue_stack;
}
