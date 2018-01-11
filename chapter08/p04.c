#include <stdio.h>
#include <string.h>
static int identity_matrix(int *matrix, int width);
int main(void)
{
	int matrix[9][9];
	memset(matrix, 0, sizeof matrix);
	int i = 0;
	for( i = 0; i < 9; ++i )
		matrix[i][i] = 1;
	matrix[8][0] = 0;
	printf("%s\n", 1 == identity_matrix((int *)matrix, 9) ? "Yes!" : "No!");
	return 0;
}
static int identity_matrix(int *matrix, int width)
{
	int i = 0;
	for( i = 0; i < width * width; ++i )
		if( i / width == i % width ) {
			if( 1 != *(matrix + i) )
				break;
		}
		else {
			if( 0 != *(matrix + i) )
				break;
		}
	if( width * width == i )
		return 1;
	for( i = 0; i < width * width; ++i )
		if( width - 1 - i / width == i % width ) {
			if( 1 != *(matrix + i) )
				break;
		}
		else {
			if( 0 != *(matrix + i) )
				break;
		}
	if( width * width == i )
		return 1;
	else
		return 0;
}
