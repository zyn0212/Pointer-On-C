#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define A 10.45
#define B 10
#define C -1
#define X 1.78816
static float wind_chill(double temp, double velocity);
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 0 & printf("Wrong input, Please input temp and velocity!\n");
	printf("wind chill is %f\n", wind_chill(atof(argv[1]), atof(argv[2])));
	return 0;
}
static float wind_chill(double temp, double velocity)
{
	double tmp = A + B * sqrt(X) + C * X;
	if( tmp >= -0.000001 && tmp <= 0.000001 )
		return 0.0;
	return (A + B * sqrt(velocity) + C * velocity) * (33 - temp) / tmp;
}
