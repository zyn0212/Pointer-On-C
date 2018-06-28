#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#ifndef P02_QUEUE_H
#define P02_QUEUE_H
extern void create_queue(size_t size);
extern void destroy_queue(void);
extern void insert(int value);
extern void delete(void);
extern int first(void);
extern int is_full(void);
extern int is_empty(void);
extern void resize(size_t size);
#endif
