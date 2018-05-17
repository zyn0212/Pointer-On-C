#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 15
typedef struct node_tag {
	int value;
	char name[MAX + 1];
	int age;
	struct node_tag *next;
} NODE;
static void PrintNodeValue(NODE * head, int needfree);
static void PrintNodeName(NODE * head, int needfree);
static void PrintNodeAge(NODE * head, int needfree);
int main(void)
{
	void(*func[3])(NODE *, int) = {PrintNodeValue, PrintNodeName, PrintNodeAge};
	srand(time(0));
	NODE * const head = (NODE *)malloc(sizeof(NODE));
	if( NULL == head )
		return 0 & printf("malloc got fatal error!\n");
	NODE * current = head;
	memset(current, 0, sizeof(NODE));
	current->value = 0;
	strcpy(current->name, "List of Name");
	current->age = -1;
	current->next = NULL;
	int i = 0;
	for( i = 1; i < 20; ++i ) {
		current->next = (NODE *)malloc(sizeof(NODE));
		current = current->next;
		if( NULL == current )
			return 0 & printf("malloc got fatal error!\n");
		current->value = i;
		int j = 0;
		char *cp = current->name;
		for( j = 0; j < 14; ++j )
			*cp++ = rand() % 26 + 'a';
		*cp = '\0';
		current->age = rand() % 30 + 20;
		current->next = NULL;
	}
	NODE *last = NULL;
	for( i = 0, current = head; i < 20 && NULL != current; ++i ) {
		last = current;
		(*func[i % 3])(current, 1);
		current = current->next;
		free(last);
	}
	return 0;
}
static void PrintNodeValue(NODE * head, int needfree)
{
	NODE *last = NULL;
	/*
	while( NULL != head ) {
		last = head;
		printf("%02d\n", head->value);
		head = head->next;
		if( needfree)
			free(last);
	}
	*/
	printf("%02d\n", head->value);
	return;
}
static void PrintNodeName(NODE * head, int needfree)
{
	NODE *last = NULL;
	/*
	while( NULL != head ) {
		last = head;
		printf("%s\n", head->name);
		head = head->next;
		if( needfree)
			free(last);
	}
	*/
	printf("%s\n", head->name);
	return;
}
static void PrintNodeAge(NODE * head, int needfree)
{
	NODE *last = NULL;
	/*
	while( NULL != head ) {
		last = head;
		printf("%d\n", head->age);
		head = head->next;
		if( needfree)
			free(last);
	}
	*/
	printf("%d\n", head->age);
	return;
}
