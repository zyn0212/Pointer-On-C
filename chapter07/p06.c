#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 256 << 1
static void written_amount(unsigned int amount, char *buffer);
static int print_number(int number, int bitnumber,char *buffer);
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return printf("Wrong parameter!\n") & 0;
	char buffer[MAX_LENGTH] = "\0";
	written_amount(atoi(argv[1]), buffer);
	printf("%s", buffer);
	return 0;
}
static void written_amount(unsigned int amount, char *buffer)
{ 
	int bitnumber = 0, base = 1;
	unsigned int tmp_a = amount;
	for( ; 0 != tmp_a; ++bitnumber, tmp_a /= 10 )
		base *= 10;
	base /= 10;
	while( bitnumber > 0 ) {
		if( bitnumber > 9 ) {
			//billion
			buffer += print_number(amount / 1000000000, (bitnumber - 1) / 3, buffer);
			amount %= 1000000000;
		}
		else if( bitnumber > 6 ) {
			//million
			buffer += print_number(amount / 1000000, (bitnumber - 1) / 3, buffer);
			amount %= 1000000;
		}
		else if( bitnumber > 3 ) {
			//thousand
			buffer += print_number(amount / 1000, (bitnumber - 1) / 3, buffer);
			amount %= 1000;
		}
		else
			//one
			buffer += print_number(amount, (bitnumber - 1) / 3, buffer);
		bitnumber = ((bitnumber + 2) / 3 - 1) * 3;
	}
	return;
}
char const *NumberNameSmall[20] = {
	"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
};
char const *NumberNameLarge[10] = {
	"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",
};
static int print_number(int number, int bitnumber, char *buffer)
{
	if( number < 0 || number > 999 || bitnumber < 0 || bitnumber > 3 || NULL == buffer )
		return 0;
	if( number / 100 > 0 )
		sprintf(buffer, "%s%s Hundred ", buffer, NumberNameSmall[number / 100]);
	number %= 100;
	if( number > 19 )
		sprintf(buffer, "%s%s %s ", buffer, NumberNameLarge[number / 10], NumberNameSmall[number % 10]);
	else
		sprintf(buffer, "%s%s ", buffer, NumberNameSmall[number]);
	switch( bitnumber ) {
		case 3:
			sprintf(buffer, "%sBillion ", buffer);
			break;
		case 2:
			sprintf(buffer, "%sMillion ", buffer);
			break;
		case 1:
			sprintf(buffer, "%sThousand ", buffer);
			break;
		default:
			sprintf(buffer, "%s\n", buffer);
			break;
	}
	return strlen(buffer);
}
