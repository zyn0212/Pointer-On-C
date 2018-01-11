#include <stdio.h>
#include <stdlib.h>
static float single_tax(float income);
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return printf("Wrong parameter!\n") & 0;
	float income = atof(argv[1]);
	printf("%.2f 's tax = %.2f\n", income, single_tax(income));
	return 0;
}
float const TAX_VALUE[6] = { 0.0, 0.15, 0.28, 0.31, 0.36, 0.396, };
float const TAX_BAND[6] = { 0.0, 0.0, 23350.0, 56550.0, 117950.0, 256500, };
static int getRank(float income);
static float single_tax(float income)
{
	float tax = 0.0;
	int rank = getRank(income);
	do {
		tax += (income - TAX_BAND[rank]) * TAX_VALUE[rank];
		income = TAX_BAND[rank];
		--rank;
	} while( rank > 0 );
	return tax;
}
static int getRank(float income)
{
	if( income < 0.001 )
		return 0;
	else if( income <= 23350.0 )
		return 1;
	else if( income <= 56550.0 )
		return 2;
	else if( income <= 117950.0 )
		return 3;
	else if( income <= 256500.0 )
		return 4;
	else
		return 5;
}
