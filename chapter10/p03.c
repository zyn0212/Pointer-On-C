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
typedef enum {
	OP_INVALID,
	OP_SINGLE,
	OP_DUAL,
	OP_MOVE,
	OP_SRC,
	OP_OTHER,
	OP_MAX,
} OP_TYPE;
typedef struct {
	OP_TYPE optype;
	union {
		SINGLE_OP singleop;
		DUAL_OP dualop;
		MOVE_OP moveop;
		SRC_OP srcop;
		OTHER_OP otherop;
	} specificop;
} OP_INFO;
int PrintOP(OP_INFO *op);
void PrintOpBit(unsigned short *value, int start);
int main(void)
{
	OP_INFO s;
	memset(&s, 0, sizeof s);
	s.optype = OP_SINGLE;
	s.specificop.singleop.opcode = 1023;
	PrintOP(&s);
	return 0;
}
int PrintOP(OP_INFO *op)
{
	if( NULL == op )
		return 1;
	switch( op->optype ) {
		case OP_SINGLE:
			PrintOpBit((unsigned short*)&op->specificop.singleop, 0);
			printf("\n");
			break;
		/*
		case OP_DUAL:
			PrintOpBit((unsigned short)op->specificop.dualop, 0);
			break;
		case OP_MOVE:
			PrintOpBit((unsigned short)op->specificop.moveop, 0);
			break;
		case OP_SRC:
			PrintOpBit((unsigned short)op->specificop.srcop, 0);
			break;
		case OP_OTHER:
			PrintOpBit((unsigned short)op->specificop.otherop, 0);
			break;
			*/
		default:
			printf("Unsupposted Operation Type!\n");
			break;
	}
	return 0;
}
void PrintOpBit(unsigned short *value, int start)
{
	if( start < BITMAX ) {
		PrintOpBit(value, start + 1);
		printf("%d ", (*value & 1 << start) > 0 ? 1 : 0);
	}
	else
		return;
}
