#include <stdio.h>
#include <string.h>
#define MATRIX_X 3
#define MATRIX_Y 2
#define MATRIX_Z 4
static int matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z);
int main(void)
{
	int A[MATRIX_X][MATRIX_Y] = { 2, -6, 3, 5, 1, -1, };
	int B[MATRIX_Y][MATRIX_Z] = { 4, -2, -4, -5, -7, -3, 6, 7, };
	int C[MATRIX_X][MATRIX_Z];
	int i = 0, j = 0;
	printf("status = %d\n", matrix_multiply(A, B, C, MATRIX_X, MATRIX_Y, MATRIX_Z));
	for( i = 0; i < MATRIX_X; ++i )
		for( j = 0; j < MATRIX_Z; ++j )
			printf("%5d%c", C[i][j], MATRIX_Z - 1 == j ? '\n' : '\t');
	return 0;
}
static int matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
	memset(r, 0, sizeof(int) * x * z );
	if( NULL == m1 || NULL == m2 || NULL == r || x < 0 || y < 0 || z < 0 )
		return -1;
	int i = 0, l = 0, k = 0;
	for( ;i < x; ++i )
		for( k = 0; k < z; ++k )
			for( l = 0; l < y; ++l )
				r[z * i + k] += m1[i * y + l] * m2[l * z + k];
	return 0;
}
