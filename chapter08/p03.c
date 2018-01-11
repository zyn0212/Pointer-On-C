#include <stdio.h>
#include <string.h>
static int identity_matrix(int *matrix);
int main(void)
{
	int matrix[10][10];
	memset(matrix, 0, sizeof matrix);
	int i = 0;
	for( i = 0; i < 10; ++i )
		matrix[9 - i][i] = 1;
	printf("%s\n", 1 == identity_matrix((int *)matrix) ? "Yes!" : "No!");
	return 0;
}
static int identity_matrix(int *matrix)
{
	int i = 0;
	for( i = 0; i < 100; ++i )
		if( i / 10 == i % 10 ) {
			if( 1 != *(matrix + i) )
				break;
		}
		else {
			if( 0 != *(matrix + i) )
				break;
		}
	if( 100 == i )
		return 1;
	for( i = 0; i < 100; ++i )
		if( 9 - i / 10 == i % 10 ) {
			if( 1 != *(matrix + i) )
				break;
		}
		else {
			if( 0 != *(matrix + i) )
				break;
		}
	if( 100 == i )
		return 1;
	else
		return 0;
}
