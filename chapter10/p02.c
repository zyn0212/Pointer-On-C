#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CUSTOMER_NAME_LENGTH 20 + 1
#define CUSTOMER_ADDR_LENGTH 40 + 1
#define PRODUCT_MODEL_LENGTH 20 + 1
typedef enum {
	PAY_INVALID,
	PAY_BY_CASH,
	PAY_BY_LOAN,
	PAY_BY_LEASE,
} PAY_TYPE;
typedef struct {
	float manufacturer_price;
	float selling_price;
	float sales_tax;
	float licensing_fee;
} BY_CASH;
typedef struct {
	float manufacturer_price;
	float selling_price;
	float down_payment;
	float security_deposit;
	float monthly_payment;
	int lease_term;
} BY_LEASE;
typedef struct {
	float manufacturer_price;
	float selling_price;
	float sales_tax;
	float licensing_fee;
	float down_payment;
	int loan_duration;
	float interest_rate;
	float monthly_payment;
	char bank_name[CUSTOMER_NAME_LENGTH];
} BY_LOAN;
typedef struct {
	char customer_name[CUSTOMER_NAME_LENGTH];
	char customer_address[CUSTOMER_ADDR_LENGTH];
	char product_model[PRODUCT_MODEL_LENGTH];
	PAY_TYPE pay_type;
	union {
		BY_CASH cash_info;
		BY_LEASE lease_info;
		BY_LOAN loan_info;
	} pay_info;
} PRODUCT_INFO;
int PrintProductInfo(PRODUCT_INFO *product_info);
int GetProductInfo(PRODUCT_INFO *product_info);
PAY_TYPE GetPayType(char *paytype);
int main(int argc, char *argv[])
{
	PRODUCT_INFO ss;
	memset(&ss, 0, sizeof ss);
	GetProductInfo(&ss);
	PrintProductInfo(&ss);
	return 0;
}
int PrintProductInfo(PRODUCT_INFO *product_info)
{
	if( NULL == product_info )
		return 1;
	printf("\tProduct information:\n----------------------------------------------\nCustomer's Name:\t%s\nCustomer's Address:\t%s\nProduct Model:\t\t%s\n", product_info->customer_name, product_info->customer_address, product_info->product_model);
	switch( product_info->pay_type ) {
		case PAY_BY_CASH:
			printf("Customer Pay Type:\tCASH\n");
			printf("Suggested Retail Price:\t%12.2f\n", product_info->pay_info.cash_info.manufacturer_price);
			printf("Actual Selling Price:\t%12.2f\n", product_info->pay_info.cash_info.selling_price);
			printf("Sales Tax:\t\t%12.2f\n", product_info->pay_info.cash_info.sales_tax);
			printf("Licensing Fee:\t\t%12.2f\n", product_info->pay_info.cash_info.licensing_fee);
			break;
		case PAY_BY_LEASE:
			printf("Customer Pay Type:\tLEASE\n");
			printf("Suggested Retail Price:\t%12.2f\n", product_info->pay_info.lease_info.manufacturer_price);
			printf("Actual Selling Price:\t%12.2f\n", product_info->pay_info.lease_info.selling_price);
			printf("Down Payment:\t\t%12.2f\n", product_info->pay_info.lease_info.down_payment);
			printf("Security Deposit:\t%12.2f\n", product_info->pay_info.lease_info.security_deposit);
			printf("Monthly Payment:\t%12.2f\n", product_info->pay_info.lease_info.monthly_payment);
			printf("Lease Term:\t\t%12.2d\n", product_info->pay_info.lease_info.lease_term);
			break;
		case PAY_BY_LOAN:
			printf("Customer Pay Type:\tLOAN\n");
			printf("Suggested Retail Price:\t%12.2f\n", product_info->pay_info.loan_info.manufacturer_price);
			printf("Actual Selling Price:\t%12.2f\n", product_info->pay_info.loan_info.selling_price);
			printf("Sales Tax:\t\t%12.2f\n", product_info->pay_info.loan_info.sales_tax);
			printf("Licensing Fee:\t\t%12.2f\n", product_info->pay_info.loan_info.licensing_fee);
			printf("Down Payment:\t\t%12.2f\n", product_info->pay_info.loan_info.down_payment);
			printf("Loan Duration:\t\t%9.2d\n", product_info->pay_info.loan_info.loan_duration);
			printf("Interest Rate:\t\t%12.2f\n", product_info->pay_info.loan_info.interest_rate);
			printf("Monthly Payment:\t%12.2f\n", product_info->pay_info.loan_info.monthly_payment);
			printf("Name of Bank:\t\t%s\n", product_info->pay_info.loan_info.bank_name);
			break;
		default:
			printf("Fatal Error:\t\tUnsuggested pay type!\n");
			break;
	}
	printf("----------------------------------------------\n");
	return 0;
}
static int checkbank(char *name)
{
	if( NULL != strstr(name, "ZGRM") )
		return 0;
	else if( NULL != strstr(name, "ICBC") )
		return 1;
	else
		return -1;
}
int GetProductInfo(PRODUCT_INFO *product_info)
{
	if( NULL == product_info )
		return 1;
	printf("Please input product information:\nCustomer's Name:\t");
	fgets(product_info->customer_name, CUSTOMER_NAME_LENGTH, stdin);
	int len_tmp = strlen(product_info->customer_name);
	if( len_tmp > 0 ) {
		if( '\n' != product_info->customer_name[len_tmp - 1] )
			while( '\n' != getchar() )
				NULL;
		else
			product_info->customer_name[len_tmp - 1] = '\0';
	}
	else {
		printf("Fatal Error: Wrong Customer's Name!\n");
		return 2;
	}
	printf("Customer's Address:\t");
	fgets(product_info->customer_address, CUSTOMER_ADDR_LENGTH, stdin);
	len_tmp = strlen(product_info->customer_address);
	if( len_tmp > 0 ) {
		if( '\n' != product_info->customer_address[len_tmp - 1] )
			while( '\n' != getchar() )
				NULL;
		else
			product_info->customer_address[len_tmp - 1] = '\0';
	}
	else {
		printf("Fatal Error: Wrong Customer's Address!\n");
		return 3;
	}
	printf("Product Model:\t\t");
	fgets(product_info->product_model, PRODUCT_MODEL_LENGTH, stdin);
	len_tmp = strlen(product_info->product_model);
	if( len_tmp > 0 ) {
		if( '\n' != product_info->product_model[len_tmp - 1] )
			while( '\n' != getchar() )
				NULL;
		else
			product_info->product_model[len_tmp - 1] = '\0';
	}
	else {
		printf("Fatal Error: Wrong Product Model!\n");
		return 4;
	}
	char str_tmp[6];
	memset(str_tmp, 0, sizeof str_tmp);
	printf("Pay Type:\t\t");
	fgets(str_tmp, 6, stdin);
	product_info->pay_type = GetPayType(str_tmp);
	if( PAY_INVALID == product_info->pay_type )
		return 5;
	switch( product_info->pay_type ) {
		case PAY_BY_CASH:
			/*
			printf("Suggested Retail Price:\t");
			while( 1 != scanf("%f", &product_info->pay_info.cash_info.manufacturer_price) && printf("Wrong input on Manufacturer Suggested Retail Price!\nSuggested Retail Price:\t") )
				while( '\n' != getchar() )
					NULL;
					*/
			while( !printf("Suggested Retail Price:\t") || 1 != scanf("%f", &product_info->pay_info.cash_info.manufacturer_price) ) {
				printf("Wrong input on Manufacturer Suggested Retail Price!\n");
				while( '\n' != getchar() )
					NULL;
			}
			printf("Actual Selling Price:\t");
			while( 1 != scanf("%f", &product_info->pay_info.cash_info.selling_price) && printf("Wrong input on Selling Price!\nActual Selling Price:\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Sales Tax:\t\t");
			while( 1 != scanf("%f", &product_info->pay_info.cash_info.sales_tax) && printf("Wrong input on Sales Tax!\nSales Tax:\t\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Licensing Fee:\t\t");
			while( 1 != scanf("%f", &product_info->pay_info.cash_info.licensing_fee) && printf("Wrong input on Licensing Fee!\nLicensing Fee:\t\t") )
				while( '\n' != getchar() )
					NULL;
			break;
		case PAY_BY_LEASE:
			printf("Suggested Retail Price:\t");
			while( 1 != scanf("%f", &product_info->pay_info.lease_info.manufacturer_price) && printf("Wrong input on Suggested Retail Price\nSuggested Retail Price\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Actual Selling Price:\t");
			while( 1 != scanf("%f", &product_info->pay_info.lease_info.selling_price) && printf("Wrong input on Actual Selling Price\nActual Selling Price\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Down Payment:\t\t");
			while( 1 != scanf("%f", &product_info->pay_info.lease_info.down_payment) && printf("Wrong input on Down Payment\nDown Payment:\t\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Security Deposit:\t");
			while( 1 != scanf("%f", &product_info->pay_info.lease_info.security_deposit) && printf("Wrong input on Security Deposit\nSecurity Deposit:\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Monthly Payment:\t");
			while( 1 != scanf("%f", &product_info->pay_info.lease_info.monthly_payment) && printf("Wrong input on Monthly Payment\nMonthly Payment:\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Lease Term:\t\t");
			while( 1 != scanf("%d", &product_info->pay_info.lease_info.lease_term) && printf("Wrong input on Lease Term\nLease Term:\t\t") )
				while( '\n' != getchar() )
					NULL;
			break;
		case PAY_BY_LOAN:
			printf("Suggested Retail Price:\t");
			while( 1 != scanf("%f", &product_info->pay_info.loan_info.manufacturer_price) && printf("Wrong input on Manufactrer Suggested Retail Price\nManufacturer Suggested Retail Price:\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Actual Selling Price:\t");
			while( 1 != scanf("%f", &product_info->pay_info.loan_info.selling_price) && printf("Wrong input on Actual Selling Price\nActual Selling Price:\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Sales Tax:\t\t");
			while( 1 != scanf("%f", &product_info->pay_info.loan_info.sales_tax) && printf("Wrong input on Sales Tax\nSales Tax:\t\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Licensing Fee:\t\t");
			while( 1 != scanf("%f", &product_info->pay_info.loan_info.licensing_fee) && printf("Wrong input on licensing Fee\nLicensing Fee:\t\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Down Payment:\t\t");
			while( 1 != scanf("%f", &product_info->pay_info.loan_info.down_payment) && printf("Wrong input on Down Payment\nDown Payment:\t\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Loan Duration:\t\t");
			while( 1 != scanf("%d", &product_info->pay_info.loan_info.loan_duration) && printf("Wrong input on Loan Duration\nLoan Duration:\t\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Interest Rate:\t\t");
			while( 1 != scanf("%f", &product_info->pay_info.loan_info.interest_rate) && printf("Wrong input on Interest Rate\nInterest Rate:\t\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Monthly Payment:\t");
			while( 1 != scanf("%f", &product_info->pay_info.loan_info.monthly_payment) && printf("Wrong input on Monthly Payment\nMonthly Payment:\t") )
				while( '\n' != getchar() )
					NULL;
			printf("Name of Bank:\t\t");
			while( !(NULL == fgets(product_info->pay_info.loan_info.bank_name, CUSTOMER_NAME_LENGTH, stdin) && -1 == checkbank(product_info->pay_info.loan_info.bank_name)) )
				printf("Wrong input on Name of Bank\nName of Bank:\t\t");
			break;
		default:
			printf("Fatal Error:\t\tUnsuggested pay type!\n");
			break;
	}
	return 0;
}
PAY_TYPE GetPayType(char *paytype)
{
	if( NULL == paytype )
		return PAY_INVALID;
	if( NULL != strstr(paytype, "cash") )
		return PAY_BY_CASH;
	else if( NULL != strstr(paytype, "lease") )
		return PAY_BY_LEASE;
	else if( NULL != strstr(paytype, "loan") )
		return PAY_BY_LOAN;
	else
		return PAY_INVALID;
}
