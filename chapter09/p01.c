#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 8
static int getkind(int c);
static void print_result(char **name, int *value);
int main(int argc, char *argv[])
{
	int sumresult[MAX];
	char *resultname[MAX] = {"控制字符", "空白字符", "数字", "小写字符", "大写字符", "标点符号", "不可打印字符", "非定义"};
	memset(sumresult, 0, sizeof sumresult);
	int c = 0;
	if( 2 > argc )
		while( EOF != (c = getchar()) )
			++sumresult[getkind(c)];
	else
		for( --argc; argc > 0; --argc )
			for( c = *argv[argc]; '\0' != c; c = *++argv[argc] )
				++sumresult[getkind(c)];
	print_result(resultname, sumresult);
	return 0;
}
static int getkind(int c)
{
	if( iscntrl(c) )
		return 0;
	else if( isspace(c) )
		return 1;
	else if( isdigit(c) )
		return 2;
	else if( isalpha(c) && islower(c) )
		return 3;
	else if( isalpha(c) && isupper(c) )
		return 4;
	else if( ispunct(c) )
		return 5;
	else if( !isprint(c) )
		return 6;
	else
		return 7;
}
static void print_result(char **name, int *value)
{
	int i = 0;
	for( i = 0; i < MAX; ++i )
		printf("%s : %3d\n", name[i], value[i]);
	if( 0 != value[i] )
		printf("%s : %3d\n", name[i], value[i]);
	return;
}
