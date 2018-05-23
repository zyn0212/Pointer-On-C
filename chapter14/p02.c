#include <stdio.h>
#include "cpu_type.h"
CPU_TYPE cpu_type(void);
int main(void)
{
	printf("%d\n", cpu_type());
	return 0;
}
CPU_TYPE cpu_type(void)
{
	CPU_TYPE retvalue = CPU_UNKNOWN;
	int isdefined = 0;
#ifdef VAX
	isdefined += 1;
	retvalue = CPU_VAX;
#endif
#ifdef M68000
	isdefined += 1;
	retvalue = CPU_68000;
#endif
#ifdef M68020
	isdefined += 1;
	retvalue = CPU_68020;
#endif
#ifdef I80386
	isdefined += 1;
	retvalue = CPU_80386;
#endif
#ifdef X6809
	isdefined += 1;
	retvalue = CPU_6809;
#endif
#ifdef X6502
	isdefined += 1;
	retvalue = CPU_6502;
#endif
#ifdef U3B2
	isdefined += 1;
	retvalue = CPU_3B2;
#endif
	return 1 == isdefined ? retvalue : CPU_UNKNOWN;
}
