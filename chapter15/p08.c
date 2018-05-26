#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINEMAX  64
static void Convert(FILE *fp);
int main(int argc, char *argv[])
{
	if( 2 == argc && 0 == strcmp(argv[1], "--help") )
		return 0 & printf("Format: command inputfile1 inputfile2 ... OR command\ninput from keyboard if command without any parameter\n");
	if( 1 == argc )
		Convert(stdin);
	else
		while( --argc > 0 ) {
			FILE *fp = fopen(argv[argc], "r");
			if( NULL == fp ) {
				printf("open file: %s failed!\n", argv[argc]);
				continue;
			}
			Convert(fp);
			fclose(fp);
			fp = NULL;
		}
	return 0;
}
static void Convert(FILE *fp)
{
	char result[LINEMAX];
	memset(result, 0, sizeof result);
	char *text = NULL, *data = NULL;
	int c = 0, loc = -1;
	while( EOF != (c = fgetc(fp)) ) {
		if( 0 == (++loc & 0xF) ) {
			if( loc > 0 ) {
				for( ; data < result + 45; ++data )
					*data = ' ';
				for( ; text < result + LINEMAX - 2; ++text )
					*text = '.';
				*text++ = '*';
				*text = '\0';
				printf("%s\n", result);
			}
			memset(result, 0, sizeof result);
			data = result;
			text = result + 45;
			data += sprintf(data, "%06X ", loc);
			*text++ = '*';
		}
		*text++ = !isprint(c) || ' ' == c ? '.' : c;
		data += sprintf(data, "%s%02X", 0 == (loc & 3) ? " " : "", c);
	}
	if( text > result + 45 ) {
		for( ; data < result + 45; ++data )
			*data = ' ';
		for( ; text < result + LINEMAX - 2; ++text )
			*text = '.';
		*text++ = '*';
		*text = '\0';
		printf("%s\n", result);
	}
	fflush(stdout);
	return;
}
