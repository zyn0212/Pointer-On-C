#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 20
typedef struct node_tag2 {
	char word[WORDLENGTH + 1];
	struct node_tag2 * next;
} NODE2;
typedef struct node_tag1 {
	int wordcount;
	NODE2 *wordlist;
}NODE1;
typedef struct list_head {
	int wordcount;
	NODE1 *body[27];
} HEAD;
typedef enum {
	INVALID,
	CHAR,
	SPACE,
	OTHER,
} WORDSTATUS;
static WORDSTATUS getWordStatus(int c);
static void MakeNode(HEAD *head, char *word);
static void PrintList(HEAD *head);
int main(int argc, char *argv[])
{
	if( 1 == argc )
		return 0 &printf("No parameter!\n");
	FILE *fp = NULL;
	HEAD const head;
	int inword = 0;
	memset(&head, 0, sizeof head);
	while( --argc > 0 ) {
		if( NULL == (fp = fopen(argv[argc], "r")) ) {
			printf("open file: %s failed!\n", argv[argc]);
			continue;
		}
		int c = 0, last = ' ';
		char wordtmp[WORDLENGTH + 1];
		memset(wordtmp, 0, sizeof wordtmp);
		char *wp = wordtmp;
		while( EOF != (c = fgetc(fp)) ) {
			if( 0 == inword && SPACE == getWordStatus(last) && CHAR == getWordStatus(c) )
				inword = 1;
			if( 1 == inword )
				if( CHAR == getWordStatus(c) )
					*wp++ = c;
				else {
					inword = 0;
					*wp = '\0';
					if( strlen(wordtmp) > 0 ) {
						MakeNode(&head, wordtmp);
						memset(wordtmp, 0, sizeof wordtmp);
						wp = wordtmp;
					}
				}
			last = c;
		}
	}
	PrintList(&head);
	return 0;
}
static WORDSTATUS getWordStatus(int c)
{
	if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' )
		return CHAR;
	else if( ' ' == c || '\t' == c || ',' == c || '.' == c )
		return SPACE;
	else if( c < 0x7F )
		return OTHER;
	else
		return INVALID;
}
static void MakeNode(HEAD *head, char *word)
{
	int firstchar = *word;
	NODE1 *node1current = NULL;
	NODE2 *node2current = NULL;
	NODE2 *last = NULL;
	node1current = head->body[firstchar & 0x1F];
	if( NULL == node1current ) {
		node1current = (NODE1 *)malloc(sizeof(NODE1));
		if( NULL == node1current ) {
			printf("malloc got fatal error!\n");
			return;
		}
		memset(node1current, 0, sizeof(NODE1));
		head->body[firstchar & 0x1F] = node1current;
	}
	node2current = node1current->wordlist;
	if( NULL == node2current ) {
		node2current = (NODE2 *)malloc(sizeof(NODE2));
		if( NULL == node2current ) {
			printf("malloc got fatal error!\n");
			return;
		}
		memset(node2current, 0, sizeof(NODE2));
		node1current->wordlist = node2current;
		strcpy(node2current->word, word);
		node1current->wordcount += 1;
		head->wordcount += 1;
	}
	else {
		int cmpvalue = strcmp(word, node2current->word);
		if( cmpvalue  < 0 ) {
			NODE2 *tmp = node1current->wordlist;
			NODE2 * newnode2 = (NODE2 *)malloc(sizeof(NODE2));
			if( NULL == newnode2 ) {
				printf("malloc got fatal error!\n");
				return;
			}
			memset(newnode2, 0, sizeof(NODE2));
			strcpy(newnode2->word, word);
			node1current->wordlist = newnode2;
			newnode2->next = tmp;
			node1current->wordcount += 1;
			head->wordcount += 1;
		}
		else if( 0 == cmpvalue )
			return;
		else {
			last = node2current;
			node2current = node2current->next;
			while( NULL != node2current ) {
				cmpvalue = strcmp(word, node2current->word);
				if( 0 == cmpvalue )
					return;
				else if( cmpvalue < 0 )
					break;
				last = node2current;
				node2current = node2current->next;
			}
			NODE2 * newnode2 = (NODE2 *)malloc(sizeof(NODE2));
			if( NULL == newnode2 ) {
				printf("malloc got fatal error!\n");
				return;
			}
			memset(newnode2, 0, sizeof(NODE2));
			strcpy(newnode2->word, word);
			last->next = newnode2;
			newnode2->next = node2current;
			node1current->wordcount += 1;
			head->wordcount += 1;
		}
	}
	return;
}
static void PrintList(HEAD *head)
{
	if( NULL == head || 0 == head->wordcount ) {
		printf("wrong parameter or no word!\n");
		return;
	}
	int i = 0;
	NODE2 * tmp = NULL;
	for( i = 1; i < 27; ++i ) {
		if( NULL != head->body[i] ) {
			printf("%c:\t", 'a'+ i - 1);
			tmp = head->body[i]->wordlist;
			while( NULL != tmp ) {
				printf("%s\t", tmp->word);
				tmp = tmp->next;
			}
		}
		putchar('\n');
	}
	return;
}
