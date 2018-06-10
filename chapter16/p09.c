#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return 0 & printf("Wrong parameter OR no parameter!\n");
	char day[365];
	srand(time(0));
	int i = 0, j = 0, birthday = 0, same = 0, number = atoi(argv[1]);
	for( ; i < 10000; ++i ) {
		memset(day, 0, sizeof day);
		for( j = 0; j < number; ++j ) {
			birthday = rand() % 365;
			++day[birthday];
			if( day[birthday] > 1 )
				++same;
		}

	}
	printf("Your input: %d, result is %.2f\n", number, (float)same / 10000);
	return 0;
}
