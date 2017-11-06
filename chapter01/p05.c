#include <stdio.h>
#define MAX 256
int main(void)
{
	char original[MAX] = "if( columns[col] >= len || output_col == MAX_INPUT - 1 )\n\t\t\tbreak;";
	char newcode[MAX] = "if( columns[col] >= len )\n\t\tcontinue;\n\tif( output_col == MAX_INPUT - 1 )\n\t\tbreak;";
	printf("original:\t%s\nnew:\t%s\n", original, newcode);
	return 0;
}
