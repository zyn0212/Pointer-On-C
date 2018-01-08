#include <stdio.h>
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return 1;
	int ret_value = 0, sign = 1;
	if( '-' == *argv[1] ){
		sign = -1;
		++argv[1];
	}
	else if( '+' == *argv[1] )
		++argv[1];
	while( '\0' != *argv[1] ) {
		if( *argv[1] >= '0' && *argv[1] <= '9' )
			ret_value = 10 * ret_value + *argv[1] - '0';
		else {
			ret_value = 0;
			break;
		}
		++argv[1];
	}
	printf("%d\n", ret_value * sign);
	return 0;
}
