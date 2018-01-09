#include <stdio.h>
#include <stdarg.h>
int max_list(int a, ...);
int main(void)
{
	printf("%d\n", max_list(22, 34234, 34466, 1151, 9009382, 23252367, 232231231, 99384396, 993295235, 0xFF24125125, -23));
	return 0;
}
int max_list(int a, ...)
{
	va_list var_arg;
	int max = a, tmp = 0;
	va_start(var_arg, a);
	while( (tmp = va_arg(var_arg, int)) > 0 )
		if( tmp > max )
			max = tmp;
	return max;
}
