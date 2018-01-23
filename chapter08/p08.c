#include <stdio.h>  
#include <stdlib.h>  
#define max 8  
int queen[max];
static int print_queen(int *queen, int width)
{
	int i = 0;
	printf(" ____ ____ ____ ____ ____ ____ ____ ____ \n");
	for( i = 0; i < width * width << 1; ++i )
		if( 0 == (i / width & 1) )
			printf("|  %c %s", i % width == queen[i / width >> 1] ? 'Q' : ' ', 0 == (i + 1) % width ? "|\n" : "");
		else
			printf("|____%s", 0 == (i + 1) % width ? "|\n" : "");
	return 0;
}
static int check(int n)
{  
    int i;  
    for(i = 0; i < n; i++)
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))  
            return 1;  
    return 0;  
}  
static void put(int n)
{  
    int i;  
    for( i = 0, queen[n] = i; i < max; queen[n] = ++i )  
        if(!check(n))  
			n == max - 1 ? print_queen(queen, 8) : put(n + 1);
	return;
}  
int main(void)  
{  
	put(0);
    return 0;  
} 
