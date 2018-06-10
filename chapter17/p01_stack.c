/*
Copyright:	zhaoyining
File name:	p01_stack.c
Description:Interface for stack
Author:		zhaoyining
Version:	0.0.0
Data:		2018-06-10
History:	2818-06-10 create
*/
#include "p01_stack.h"
static int *stack;
static size_t stack_size;
static int top_element = -1;
static int is_full(void);
static int is_empty(void);
void create_stack(size_t size)
{
	assert(0 == stack_size);
	stack_size = size;
	stack = calloc(stack_size, sizeof(int));
	assert(!(NULL == stack));
	return;
}
void destroy_stack(void)
{
	assert(!(stack_size <= 0));
	stack_size = 0;
	free(stack);
	stack = NULL;
	return;
}
void push(int value)
{
	assert(!is_full());
	stack[++top_element] = value;
	return;
}
int pop(void)
{
	assert(!is_empty());
	return stack[top_element--];
}
int top(void)
{
	assert(!is_empty());
	return stack[top_element];
}
int is_full(void)
{
	assert(!(stack_size <= 0));
	return top_element == stack_size - 1;
}
int is_empty(void)
{
	assert(!(stack_size <= 0));
	return top_element == - 1;
}
void resize_stack(size_t newsize)
{
	if( newsize < 1 || newsize == stack_size )
		return;
	int *res = (int *)realloc(stack, newsize * sizeof(int));
	assert(!(NULL == res));
	stack_size = newsize;
	stack = res;
}
