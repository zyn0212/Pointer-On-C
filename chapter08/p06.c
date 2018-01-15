#include <stdio.h>
#include <string.h>
#include <stdarg.h>
static int array_offset(int *arrayinfo, ...);
int main(void)
{
	int s0[] = {3, 4, 6, 1, 5, -3, 3,};
	printf("%d\n", array_offset(s0, 4, 1, -3));
	printf("%d\n", array_offset(s0, 4, 1, -2));
	printf("%d\n", array_offset(s0, 4, 1, 3));
	printf("%d\n", array_offset(s0, 4, 2, -3));
	printf("%d\n", array_offset(s0, 5, 1, -3));
	printf("%d\n", array_offset(s0, 6, 3, 1));
	return 0;
}
static int array_offset(int *arrayinfo, ...)
{
	if( NULL == arrayinfo )
		return -1;
	int i = 0, loc = 1, ret_value = 0, j = 2;
	int length[11];
	memset(length, 0, sizeof length);
	for( i = arrayinfo[0] << 1, length[0] = 1, length[1] = 1; i > 0; i -= 2, ++j )
		length[j] = (arrayinfo[i] - arrayinfo[i - 1] + 1) * length[j - 1];
	va_list var_arg;
	va_start(var_arg, arrayinfo);
	for( i = 1, loc = va_arg(var_arg, int); i <= arrayinfo[0]; ++i, loc = va_arg(var_arg, int) )
		if( arrayinfo[(i << 1) - 1] <= arrayinfo[i << 1] && loc >= arrayinfo[(i << 1) - 1] && loc <= arrayinfo[i << 1] ) 
			ret_value += (loc - arrayinfo[(i << 1) - 1]) * length[arrayinfo[0] - i + 1];
		else {
			va_end(var_arg);
			return -1;
		}
	va_end(var_arg);
	return ret_value;
}
