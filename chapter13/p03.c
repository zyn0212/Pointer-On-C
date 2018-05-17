#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum {
	NEW,
	DELETE,
	FORWARD,
	BACKWARD,
	SEARCH,
	EDIT,
	OTHER,
	MAX,
} ENUM_TRANS_TYPE;
typedef struct node_tag {
	int value;
	struct node_tag *next;
} NODE;
static void NewNode(NODE *base, NODE *node);
static void DeleteNode(NODE *base, NODE *node);
static void ForwardNode(NODE *base, NODE *node);
static void BackwardNode(NODE *base, NODE *node);
static void SearchNode(NODE *base, NODE *node);
static void EditNode(NODE *base, NODE *node);
static void Other(NODE *base, NODE *node);
int main(void)
{
	srand(time(0));
	void (*func[MAX])(NODE *, NODE *) = {
		NewNode,
		DeleteNode,
		ForwardNode,
		BackwardNode,
		SearchNode,
		EditNode,
		Other,
	};
	NODE *a = NULL, *b = NULL;
	int i = 0;
	for( i = 0; i < 40; ++i )
		(*func[rand() % MAX])(a, b);
	return 0;
}
static void NewNode(NODE *base, NODE *node)
{
	printf("make a new node!\n");
}
static void DeleteNode(NODE *base, NODE *node)
{
	printf("delete a node!\n");
}
static void ForwardNode(NODE *base, NODE *node)
{
	printf("make a node forward!\n");
}
static void BackwardNode(NODE *base, NODE *node)
{
	printf("make a node backward!\n");
}
static void SearchNode(NODE *base, NODE *node)
{
	printf("search a node in base!\n");
}
static void EditNode(NODE *base, NODE *node)
{
	printf("edit a node in base!\n");
}
static void Other(NODE *base, NODE *node)
{
	printf("Illegal transaction type!\n");
}
