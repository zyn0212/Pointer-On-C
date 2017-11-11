#include <stdio.h>
#include <string.h>
#define MAX 20
void set_bit(char bit_array[],unsigned bit_number);
void clear_bit(char bit_array[],unsigned bit_number);
void assign_bit(char bit_array[],unsigned bit_number, int value);
int test_bit(char bit_array[],unsigned bit_number);
int main(void)
{
	char base[MAX];
	memset(base, 0, sizeof base);
	assign_bit(base, 151, 1);
	int i = 0;
	for( i = 0; i < MAX; ++i )
		printf("%d,", base[i]);
	putchar('\n');
	printf("%d\n", test_bit(base, 151));
	assign_bit(base, 151, 0);
	for( i = 0; i < MAX; ++i )
		printf("%d,", base[i]);
	putchar('\n');
	return 0;
}
void set_bit(char bit_array[],unsigned bit_number)
{
	char tmp = 1;
	bit_array[bit_number >> 3] |= tmp << (bit_number & 0x7);
}
void clear_bit(char bit_array[],unsigned bit_number)
{
	char tmp = 1;
	bit_array[bit_number >> 3] &= ~(tmp << (bit_number & 0x7));
}
void assign_bit(char bit_array[],unsigned bit_number, int value)
{
	if( 0 == value )
		clear_bit(bit_array, bit_number);
	else
		set_bit(bit_array, bit_number);
}
int test_bit(char bit_array[],unsigned bit_number)
{
	char tmp = 1;
	return bit_array[bit_number >> 3] & tmp << (bit_number & 0x7);
}
