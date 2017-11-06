#include <stdio.h>
#define MAX 256
int main(void)
{
	char original[MAX] = "for( col = 0; col < n_columns; col+= 2 ) {";
	char newcode[MAX] = "for( col = 0; col < n_columns; col += col + 1 == n_columns ? 1 : 2) {";
	printf("original:\t%s\nnew:\t%s\n", original, newcode);
	return 0;
}
