#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef P01_STACK_H
#define P01_STACK_H
extern void resize_stack(size_t newsize);
extern int top(void);
extern int pop(void);
extern void push(int value);
extern void create_stack(size_t size);
extern void destroy_stack(void);
#endif
