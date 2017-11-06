#include <stdio.h>
#include <string.h>
#define STRMAX 1000
int main(void)
{
	char result[STRMAX - 1], tmp[STRMAX - 1];
	int maxlen = 0, len = 0;
	memset(result, 0, sizeof result);
	memset(tmp, 0, sizeof tmp);
	while( NULL != fgets(tmp, STRMAX - 1, stdin) && (len = strlen(tmp)) > 0 )
		if( len > maxlen ) {
			maxlen = len;
			strncpy(result, tmp, len);
		}
	printf("the max length of your input is :\n%s%s", result, '\n' == result[maxlen - 1] ? "" : "\n");
	return 0;
}
