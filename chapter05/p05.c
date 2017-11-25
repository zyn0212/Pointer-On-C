/*There is a mistake in book, value of mask disappear a 0*/
#include <stdio.h>
static int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit);
int main(void)
{
	printf("original\tvalue\treturn\n");
	printf("%#x\t\t%#x\t%#x\n", 0, 1, store_bit_field(0, 1, 4, 4));
	printf("%#x\t\t%#x\t%#x\n", 0xFFFF, 0x123, store_bit_field(0xFFFF, 0x123, 15, 4));
	printf("%#x\t\t%#x\t%#x\n", 0xFFFF, 0x123, store_bit_field(0xFFFF, 0x123, 13, 9));

	return 0;
}
static int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit)
{
	int mask = (1 << starting_bit - ending_bit + 1) - 1 << ending_bit;
	return original_value & ~mask | value_to_store << ending_bit & mask;
}
