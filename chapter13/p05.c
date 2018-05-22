#include <stdio.h>
#define CTRLMAX 20
static void illegal_arg(int c);
static void do_arg(int c, char *v);
static char **do_args(int argc, char *argv[], char *control, void(*do_arg)(int ch, char *value), void (*illegal_arg)(int ch));
static int check(int c, char *v);
char g_control[CTRLMAX] = "";
int main(int argc, char *argv[])
{
	scanf("%s", g_control);
	while( '\n' != getchar() )
		NULL;
	printf("control:%s\n", g_control);
	do_args(argc, argv, g_control, do_arg, illegal_arg);
	return 0;
}
static void illegal_arg(int c)
{
	printf("(*illegal)('%c')\n", c);
	return;
}
static void do_arg(int c, char *v)
{
	printf("(*do_arg)(%c, %s)\n", c, NULL == v ? "0" : v);
	return;
}
static char **do_args(int argc, char *argv[], char *control, void(*do_arg)(int ch, char *value), void (*illegal_arg)(int ch))
{
	int i = 0, c = 0, checkvalue = 0;
	char *argvp = NULL;
	for( i = 1, argvp = argv[i]; i < argc; argvp = argv[++i] ) {
		if( '-' != *argvp++ )
			break;
		while( '\0' != (c = *argvp++) )
			if( -1 == (checkvalue = check(c, control)) )
				illegal_arg(c);
			else if( '+' != checkvalue )
				do_arg(c, NULL);
			else if( '\0' == *argvp  && NULL == argv[i + 1] )
				illegal_arg(c);
			else {
				do_arg(c, '\0' == *argvp ? argv[++i] : argvp);
				break;
			}
	} 
	printf("return &argv[%d]\n", i);
	return &argv[i];
}
int check(int c, char *v)
{
	while( '\0' != *v )
		if( c == *v++ ) {
			if( '\0' != *v )
				return *v;
			else
				return 1;
		}
	return -1;
}
