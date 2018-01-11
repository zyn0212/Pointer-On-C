#include <stdio.h>
#include <stdarg.h>
int sim_print(char *format, ...);
static int print_int(int n);
static int print_flt(double n);
static int print_str(char *s);
int main(void)
{
	printf("%d\n", sim_print("nihao %s, %d, %d, %f, %c, %d\n", "shijie", 33252, 22362, 3.1415926, 'p', -12345));
	return 0;
}
int sim_print(char *format, ...)
{
	int ret_value = 0;
	va_list var_arg;
	va_start(var_arg, format);
	while( '\0' != *format ) {
		if( '%' != *format ) {
			putchar(*format);
			++ret_value;
		}
		else {
			++format;
			switch( *format ) {
				case 's':
					ret_value += print_str(va_arg(var_arg, char*));
					break;
				case 'd':
					ret_value += print_int(va_arg(var_arg,int));
					break;
				case 'f':
					ret_value += print_flt(va_arg(var_arg,double));
					break;
				case 'c':
					putchar(va_arg(var_arg, int));
					++ret_value;
					break;
				default:
					va_end(var_arg);
					return -2;
					break;
			}
		}
		++format;
	}
		va_end(var_arg);
	return ret_value;
}
static int print_int(int n)
{
	int charnumber = 0, base = 1, tmp_n = 0;
	if( 0 == n ) {
		putchar('0');
		return 0;
	}
	else if( n < 0 ) {
		putchar('-');
		++charnumber;
		n = -n;
	}
	tmp_n = n;
	for( ; 0 != tmp_n; ++charnumber, tmp_n /= 10 )
		base *= 10;
	base /= 10;
	for( ; 0 != n; n %= base, base /= 10 )
		putchar('0' + n / base);
	return charnumber;
}
static int print_flt(double n)
{
	int charnumber = 0;
	charnumber += print_int((int)n);
	double tmp = n - (int)n > 0 ? n - (int)n : (int)n - n;
	if( tmp  <= 0.00000001 )
		return charnumber;
	++charnumber;
	putchar('.');
	while( tmp > 0.00000001 ) {
		++charnumber;
		tmp *= 10;
		putchar('0' + (int)tmp);
		tmp -= (int)tmp;
	}
	return charnumber;
}
static int print_str(char *s)
{
	int charnumber = 0;
	for( ; '\0' != *s; ++charnumber, ++s)
		putchar(*s);
	return charnumber;
}
