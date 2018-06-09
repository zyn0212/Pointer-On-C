#include <stdio.h>
#include <stdlib.h>
#include <math.h>
static double payment(double amount, double interest, int years);
int main(int argc, char *argv[])
{
	if( 4 != argc )
		return 0 & printf("Wrong parameters, Please input amount, interest years\n");
	printf("Payment is %.2f\n", payment(atof(argv[1]), atof(argv[2]) / 1200, atoi(argv[3])));
	return 0;
}
static double payment(double amount, double interest, int years)
{
	double retvalue = 1 - pow(1 + interest, -1 * years * 12);
	if( retvalue >= -0.000001 && retvalue <= 0.000001 )
		return 0.0;
	return round(amount * interest * 100 / retvalue) / 100;
}
