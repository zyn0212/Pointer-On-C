#include <stdio.h>
#include <math.h>
#define PRECISION 0.0000001
static double GetResult(double n);
int main(void)
{
	double n = 0.0;
	if( 1 != scanf("%lf", &n) ) {
		printf("wrong input!\n");
		return 1;
	}
	printf("final = %f\n", GetResult(n));
	printf("math = %f\n", sqrt(n));
	return 0;
}
static double GetResult(double n)
{
	double last = 1.0, current = 0.0;
	while( fabs((current = (last + n / last ) / 2) - last) > PRECISION )
		printf("last = %f\n", last = current);
	return current;
}
