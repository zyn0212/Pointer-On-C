#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(int argc, char *argv[])
{
	if( 4 != argc )
		return 0 & printf("Wrong input, Please input Month(1~12), Day(1~31), Year(0~\?\?)\n");
	struct tm tmp;
	memset(&tmp, 0, sizeof tmp);
	tmp.tm_mon = atoi(argv[1]) - 1;
	tmp.tm_mday = atoi(argv[2]);
	tmp.tm_year = atoi(argv[3]) - 1900;
	if( tmp.tm_mon < 0 || tmp.tm_mon > 11 || tmp.tm_mday < 1 || tmp.tm_mday > 31 )
		return 0 & printf("Out range of day or month!\n");
	mktime(&tmp);
	printf("%dth day in week!\n", tmp.tm_wday);
	return 0;
}
