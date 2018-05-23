#include <stdio.h>
static void print_ledger(int n);
static void print_ledger_long(int n);
static void print_ledger_detailed(int n);
static void print_ledger_default(int n);
int main(void)
{
	print_ledger(5);
	return 0;
}
static void print_ledger(int n)
{
#ifdef OL
	print_ledger_long(n);
#endif
#ifdef OD
	print_ledger_detailed(n);
#endif
	print_ledger_default(n);
	return;
}
static void print_ledger_long(int n)
{
	printf("%s:%d\n", __func__, n);
}
static void print_ledger_detailed(int n)
{
	printf("%s:%d\n", __func__, n);
}
static void print_ledger_default(int n)
{
	printf("%s:%d\n", __func__, n);
}
