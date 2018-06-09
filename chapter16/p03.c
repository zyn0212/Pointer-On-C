#include <stdio.h>
#include <string.h>
#include <time.h>
int main(void)
{
	time_t t = time(0);
	struct tm *tmp = localtime(&t);
	if( 0 == tmp->tm_min )
		printf("Hour hand on %d, Minute hand on %d\n", tmp->tm_hour, tmp->tm_min);
	else
		printf("Hour hand between %d and %d, Minute hand on %d\n", tmp->tm_hour, 1 + tmp->tm_hour, tmp->tm_min);
	return 0;
}
