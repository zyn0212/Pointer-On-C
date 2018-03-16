#include <stdio.h>
#include <string.h>
#define BITMAX 16
typedef struct {
	unsigned short dst_reg	: 3;
	unsigned short dst_mode	: 3;
	unsigned short opcode	: 10;
} SINGLE_OP;
typedef struct {
	unsigned short dst_reg	: 3;
	unsigned short dst_mode	: 3;
	unsigned short src_reg	: 3;
	unsigned short src_mode	: 3;
	unsigned short opcode	: 4;
} DUAL_OP;
typedef struct {
	unsigned short offset	: 8;
	unsigned short opcode	: 8;
} MOVE_OP;
typedef struct {
	unsigned short dst_reg	: 3;
	unsigned short dst_mode	: 3;
	unsigned short src_reg	: 3;
	unsigned short opcode	: 7;
} SRC_OP;
typedef struct {
	unsigned short opcode	: 16;
} OTHER_OP;
typedef union {
		unsigned short addr;
		SINGLE_OP sgl_leop;
		DUAL_OP dbl_op;
		MOVE_OP branch;
		SRC_OP reg_srcop;
		OTHER_OP misc;
} machine_inst;
int PrintOpBit(unsigned short *value);
int main(void)
{
	machine_inst x;
	memset(&x, 0, sizeof x);
	x.addr = 0xFF;
	x.misc.opcode = 0xF0F0;
	PrintOpBit((unsigned short*)&x);
	return 0;
}
static void PrintOpBitValue(unsigned short *value, int start);
int PrintOpBit(unsigned short *value)
{
	if( NULL == value )
		return 1;
	PrintOpBitValue(value, 0);
	printf("\n");
	return 0;
}
static void PrintOpBitValue(unsigned short *value, int start)
{
	if( start < BITMAX ) {
		PrintOpBitValue(value, start + 1);
		printf("%d ", (*value & 1 << start) > 0 ? 1 : 0);
	}
}
