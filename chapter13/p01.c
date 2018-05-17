#include <stdio.h>
#include <ctype.h>
typedef enum {
	CTRLCHAR,
	SPACECHAR,
	DIGITCHAR,
	LOWERCHAR,
	UPPERCHAR,
	PUNCTCHAR,
	OTHERCHAR, 
	TOTAL,
	MAX,
} CHARSTATUS;
char *g_namelist[TOTAL] = {
	"Ctrlchar",
	"Spacechar",
	"Digitchar",
	"Lowerchar",
	"Upperchar",
	"Punctchar",
	"Otherchar",
};
int g_Result[MAX];
static int getCharStatus(int c);
int main(int argc, char *argv[])
{
	if( 1 == argc )
		return 0 & printf("no input file!\n");
	FILE *fp = NULL;
	int c = 0;
	while( --argc > 0 ) {
		fp = fopen(argv[argc], "r");
		if( NULL == fp ) {
			printf("open file: %s failed!\n", argv[argc]);
			continue;
		}
		while( EOF != (c = fgetc(fp)) ) {
			g_Result[TOTAL] += 1;
			switch( getCharStatus(c) ) {
				case 1 << CTRLCHAR:
					g_Result[CTRLCHAR] += 1;
					break;
				case 1 << SPACECHAR:
					g_Result[SPACECHAR] += 1;
					break;
				case 1 << DIGITCHAR:
					g_Result[DIGITCHAR] += 1;
					break;
				case 1 << LOWERCHAR:
					g_Result[LOWERCHAR] += 1;
					break;
				case 1 << UPPERCHAR:
					g_Result[UPPERCHAR] += 1;
					break;
				case 1 << PUNCTCHAR:
					g_Result[PUNCTCHAR] += 1;
					break;
				default:
					g_Result[OTHERCHAR] += 1;
					break;
			}
		}
		fclose(fp);
		fp = NULL;
	}
	if( 0 == g_Result[TOTAL] )
		return 0;
	int i = 0;
	for( i = CTRLCHAR; i < TOTAL; ++i )
		printf("%s\t%.2f\n", g_namelist[i], (float)g_Result[i]/g_Result[TOTAL]);
	return 0;
}
static int getCharStatus(int c)
{
	int retvalue = 0;
	retvalue |= (iscntrl(c) ? 1 : 0) << CTRLCHAR;
	retvalue |= (isspace(c) ? 1 : 0) << SPACECHAR;
	retvalue |= (isdigit(c) ? 1 : 0) << DIGITCHAR;
	retvalue |= (islower(c) ? 1 : 0) << LOWERCHAR;
	retvalue |= (isupper(c) ? 1 : 0) << UPPERCHAR;
	retvalue |= (ispunct(c) ? 1 : 0) << PUNCTCHAR;
	return retvalue;
}
