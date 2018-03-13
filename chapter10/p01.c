#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define QUHAO 3
#define JIAOHUAN 8
#define ZHANHAO 4
typedef struct {
	unsigned long call_src;
	unsigned long call_dest;
	long call_time;
	unsigned long pay_number;
} CALL_INFORMATION;
/*
   PhoneNumber format:	xxx-xxxxxxxx-xxxx
   CallTime format:		yyyy-mm-dd hh:mm:ss
   */
int SaveCallInfo(char *call_src, char *call_dest, char *call_time, char *pay_number, CALL_INFORMATION *call_info);
int PrintCallInfo(CALL_INFORMATION *call_info);
int main(int argc, char *argv[])
{
	CALL_INFORMATION ss;
	memset(&ss, 0, sizeof ss);
	//SaveCallInfo("021-88318484-5", "022-4234252-6", "2018-4-3 12:34:56", "", &ss);
	SaveCallInfo(argv[1], argv[2], argv[3], argv[4], &ss);
	PrintCallInfo(&ss);
	return 0;
}
int PrintCallInfo(CALL_INFORMATION *call_info)
{
	if( NULL == call_info )
		return 1;
	printf("Call Information:\nFrom:\t%0*lu - %*lu", QUHAO, call_info->call_src >> 48 & 0xFFFF, JIAOHUAN, call_info->call_src >> 16 & 0xFFFFFFFF);
	if( 0 != (call_info->call_src & 0xFFFF) )
		printf(" - %-*lu\n", ZHANHAO, call_info->call_src & 0xFFFF);
	else
		printf("\n");
	printf("To:\t%0*lu - %*lu", QUHAO, call_info->call_dest >> 48 & 0xFFFF, JIAOHUAN, call_info->call_dest >> 16 & 0xFFFFFFFF);
	if( 0 != (call_info->call_dest & 0xFFFF) )
		printf(" - %-*lu\n", ZHANHAO, call_info->call_dest & 0xFFFF);
	else
		printf("\n");
	printf("PayBy:\t%0*lu - %*lu", QUHAO, call_info->pay_number >> 48 & 0xFFFF, JIAOHUAN, call_info->pay_number >> 16 & 0xFFFFFFFF);
	if( 0 != (call_info->pay_number & 0xFFFF) )
		printf(" - %-*lu\n", ZHANHAO, call_info->pay_number & 0xFFFF);
	else
		printf("\n");
	printf("Time:\t%s\n", ctime(&call_info->call_time));
	return 0;
}
static unsigned long get_phonenumber(char *number);
static unsigned long get_calltime(char *calltime);
int SaveCallInfo(char *call_src, char *call_dest, char *call_time, char *pay_number, CALL_INFORMATION *call_info)
{
	if( NULL == call_info || NULL == call_src || NULL == call_dest || NULL == call_time )
		return 1;
	call_info->call_src = get_phonenumber(call_src);
	call_info->call_dest = get_phonenumber(call_dest);
	unsigned long number_tmp = get_phonenumber(pay_number);
	call_info->pay_number = 0 == number_tmp ? call_info->call_src : number_tmp;
	call_info->call_time = get_calltime(call_time);
	return 0;
}
static unsigned long get_phonenumber(char *number)
{
	if( NULL == number )
		return 0;
	int i = 0;
	unsigned long number_tmp = 0, result = 0;
	while( '\0' != *number && !isdigit(*number) )
		++number;
	for( ; '\0' != *number && i < QUHAO && isdigit(*number); ++i, ++number )
		number_tmp = number_tmp * 10 + *number - '0';
	if( i > QUHAO )
		return 0;
	result = (number_tmp & 0xFFFF) << 48;
	while( '\0' != *number && '-' != *number )
		++number;
	while( '\0' != *number && !isdigit(*number) )
		++number;
	for( i = 0, number_tmp = 0; '\0' != *number && i < JIAOHUAN && isdigit(*number); ++i, ++number )
		number_tmp = number_tmp * 10 + *number - '0';
	if( i > JIAOHUAN )
		return 0;
	result |= (number_tmp & 0xFFFFFFFF) << 16;
	while( '\0' != *number && '-' != *number )
		++number;
	while( '\0' != *number && !isdigit(*number) )
		++number;
	for( i = 0, number_tmp = 0; '\0' != *number && i < ZHANHAO && isdigit(*number); ++i, ++number )
		number_tmp = number_tmp * 10 + *number - '0';
	if( i > ZHANHAO )
		return result;
	result |= number_tmp & 0xFFFF;
	return result;
}
static unsigned long get_calltime(char *calltime)
{
	if( NULL == calltime )
		return 0;
	int i = 0, timevalue = 0;
	struct tm tmp;
	memset(&tmp, 0, sizeof tmp);
	while( '\0' != *calltime && !isdigit(*calltime) )
		++calltime;
	for( ; '\0' != *calltime && i < 4 && isdigit(*calltime); ++i, ++calltime )
		timevalue = timevalue * 10 + *calltime - '0';
	if( i > 4 )
		return 0;
	tmp.tm_year = timevalue - 1900;
	while( '\0' != *calltime && '-' != *calltime )
		++calltime;
	while( '\0' != *calltime && !isdigit(*calltime) )
		++calltime;
	for( i = 0, timevalue = 0; '\0' != *calltime && i < 2 && isdigit(*calltime); ++i, ++calltime )
		timevalue = timevalue * 10 + *calltime - '0';
	--timevalue;
	if( i > 2 || timevalue < 0 || timevalue > 11 )
		return 0;
	tmp.tm_mon = timevalue;
	while( '\0' != *calltime && '-' != *calltime )
		++calltime;
	while( '\0' != *calltime && !isdigit(*calltime) )
		++calltime;
	for( i = 0, timevalue = 0; '\0' != *calltime && i < 2 && isdigit(*calltime); ++i, ++calltime )
		timevalue = timevalue * 10 + *calltime - '0';
	if( i > 2 || timevalue < 1 || timevalue > 31)
		return 0;
	tmp.tm_mday = timevalue;
	while( '\0' != *calltime && !isdigit(*calltime) )
		++calltime;
	for( i = 0, timevalue = 0; '\0' != *calltime && i < 2 && isdigit(*calltime); ++i, ++calltime )
		timevalue = timevalue * 10 + *calltime - '0';
	if( i > 2 || timevalue < 0 || timevalue > 23)
		return 0;
	tmp.tm_hour = timevalue;
	while( '\0' != *calltime && ':' != *calltime )
		++calltime;
	while( '\0' != *calltime && !isdigit(*calltime) )
		++calltime;
	for( i = 0, timevalue = 0; '\0' != *calltime && i < 2 && isdigit(*calltime); ++i, ++calltime )
		timevalue = timevalue * 10 + *calltime - '0';
	if( i > 2 || timevalue < 0 || timevalue > 59 )
		return 0;
	tmp.tm_min = timevalue;
	while( '\0' != *calltime && ':' != *calltime )
		++calltime;
	while( '\0' != *calltime && !isdigit(*calltime) )
		++calltime;
	for( i = 0, timevalue = 0; '\0' != *calltime && i < 2 && isdigit(*calltime); ++i, ++calltime )
		timevalue = timevalue * 10 + *calltime - '0';
	if( i > 2 || timevalue < 0 || timevalue > 59 )
		return 0;
	tmp.tm_sec = timevalue;
	return mktime(&tmp);
}
