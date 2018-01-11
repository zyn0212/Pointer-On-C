#include <stdio.h>
#include <string.h>
int main(void)
{
	int char_value[3][6][4][5];
	memset(char_value, 0, sizeof char_value);
	char_value[1][2][2][3] = 'A';
	char_value[1][1][1][1] = ' ';
	char_value[1][3][2][2] = 0xF3;
	char_value[2][4][3][2] = '3';
	char_value[1][4][2][3] = '\n';
	char_value[2][2][3][1] = '\121';
	char_value[2][4][3][3] = 3;
	char_value[2][5][3][4] = 125;
	char_value[1][2][3][4] = 'x';
	char_value[2][1][1][2] = 0320;
	char_value[2][2][2][2] = '\'';
	char_value[2][2][1][1] = '0';
	int i = 0, j = 0, k = 0, l = 0;
	for( i = 0; i < 3; ++i )
		for( j = 0; j < 6; ++j ) {
			for( k = 0; k < 4; ++k )
				for( l = 0; l < 5; ++l )
					printf("%6x ", char_value[i][j][k][l]);
			putchar('\n');
		}
	return 0;
}
