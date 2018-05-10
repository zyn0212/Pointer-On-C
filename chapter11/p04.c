#include <stdio.h>
#include <stdlib.h>
typedef struct example {
	int value;
	struct example *next;
} EXP;
int main(void)
{
	EXP * const head = (EXP *)malloc(sizeof(EXP));
	EXP *loop = head;
	if( NULL == head )
		return 0 & printf("malloc got fatal error!\n");
	loop->value = 0;
	int i = 0;
	for( i = 2; i < 12; ++i ) {
		loop->next = (EXP *)malloc(sizeof(EXP));
		if( NULL == loop->next )
			return 0 & printf("malloc got fatal error!\n");
		loop = loop->next;
		loop->value = i << 3;
	}
	loop->next = NULL;
	loop = head;
	EXP *forfree = NULL;
	while( NULL != loop ) {
		printf("%d\n", loop->value);
		forfree = loop;
		loop = loop->next;
		free(forfree);
	}
	loop = NULL;
	forfree = NULL;
	return 0;
}
