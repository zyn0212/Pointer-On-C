#include "p02_queue.h"
typedef struct queue_node {
	int value;
	struct queue_node *next;
} QUEUE_NODE;
struct {
	int element_count;
	int queue_size;
	QUEUE_NODE *first;
	QUEUE_NODE *last;
} queue_ptr = { 0, 0, NULL, NULL};
void create_queue(size_t size)
{
	assert( !(0 != queue_ptr.element_count || 0 == size) );
	int i = 0;
	QUEUE_NODE * const head = (QUEUE_NODE *)calloc(1, sizeof(QUEUE_NODE));
	QUEUE_NODE *current = NULL;
	assert( !(NULL == head) );
	current = head;
	queue_ptr.first = head;
	queue_ptr.last = head;
	for( i = 0; i < size; ++i ) {
		current->next = (QUEUE_NODE *)calloc(1, sizeof(QUEUE_NODE));
		assert( !(NULL == current->next) );
		current = current->next;
	}
	current->next = head;
	queue_ptr.queue_size = size;
}
void destroy_queue(void)
{
	assert( is_empty() );
	QUEUE_NODE *current = queue_ptr.first;
	QUEUE_NODE *last = NULL;
	int i = 0;
	for( i = 0; i < queue_ptr.queue_size; ++i ) {
		last = current;
		current = current->next;
		free(last);
	}
}
void insert(int value)
{
	assert( !is_full() );
	queue_ptr.last->value = value;
	queue_ptr.last = queue_ptr.last->next;
	++queue_ptr.element_count;
}
void delete(void)
{
	assert( !is_empty() );
	first();
}
int first(void)
{
	assert( !is_empty() );
	int retvalue = queue_ptr.first->value;
	--queue_ptr.element_count;
	queue_ptr.first = queue_ptr.first->next;
	return retvalue;
}
int is_full(void)
{
	return queue_ptr.element_count == queue_ptr.queue_size;
}
int is_empty(void)
{
	return 0 == queue_ptr.element_count;
}
void resize(size_t size)
{
	assert( !(0 == queue_ptr.queue_size) );
	assert( !(size < queue_ptr.element_count) );
	QUEUE_NODE * const gap_head = queue_ptr.last;
	QUEUE_NODE * const gap_tail = queue_ptr.last->next;
	QUEUE_NODE * current = NULL;
	QUEUE_NODE * last = NULL;
	queue_ptr.queue_size = size;
	if( size < queue_ptr.queue_size ) {
		current = queue_ptr.last->next;
		while( size++ < queue_ptr.queue_size ) {
			last = current;
			current = current->next;
			free(last);
			last = NULL;
		}
		gap_head->next = current;
	}
	else {
		QUEUE_NODE * current = queue_ptr.last;
		while( size++ < queue_ptr.queue_size ) {
			current->next = (QUEUE_NODE *)calloc(1, sizeof(QUEUE_NODE));
			assert( !(NULL == current->next) );
			current = current->next;
		}
		current->next = gap_tail;
	}
}
