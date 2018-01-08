#include "../../zyn_lib.h"
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 1;
	printf("%d\n", gcd(atoi(argv[1]), atoi(argv[2])));
	return 0;
}
