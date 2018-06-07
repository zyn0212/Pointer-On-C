#include <stdio.h>
#define FINAL 29
static int getResult(int age);
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return 0 & printf("Wrong parameters OR No parameter!\n");
	int age = 0;
	char *pctmp = argv[1];
	while( '\0' != *pctmp ) {
		if( *pctmp >= '0' && *pctmp <= '9' )
			age = age * 10 + *pctmp - '0';
		else
			break;
		++pctmp;
	}
	if( '\0' != *pctmp )
		return 0;
	printf("%d\n", getResult(age));
	return 0;
}
static int getResult(int age)
{
	int retvalue = 0;
	if( FINAL > 99 )
		return 0;
	if( FINAL > 9 ) {
		if( 0 == (age - FINAL % 10) % (FINAL / 10 % 10) )
			retvalue = (age - FINAL % 10) / (FINAL / 10 % 10);
		else
			return 0;
	}
	else
		return 0;
	if( retvalue >= 2 && retvalue <= 36 )
		return retvalue;
	else
		return 0;
}
