#include <stdio.h>  
#include <stdlib.h>  
   
#define max 8  
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
   
int queen[max], sum=0; /* max为棋盘最大坐标 */  
   
void show() /* 输出所有皇后的坐标 */  
{  
    int i;  
    for(i = 0; i < max; i++)  
    {  
         printf("(%d,%d) ", i, queen[i]);  
    }  
    printf("\n");  
    sum++;  
}  
   
int check(int n) /* 检查当前列能否放置皇后 */  
{  
    int i;  
    for(i = 0; i < n; i++) /* 检查横排和对角线上是否可以放置皇后 */  
    {  
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))  
        {  
            return 1;  
        }  
    }  
    return 0;  
}  
   
void put(int n) /* 回溯尝试皇后位置,n为横坐标 */  
{  
    int i;  
    for(i = 0; i < max; i++)  
    {         
        queen[n] = i; /* 将皇后摆到当前循环到的位置 */  
        if(!check(n))  
        {             
            if(n == max - 1)  
            {  
				print_queen(queen, 8);
//                show(); /* 如果全部摆好，则输出所有皇后的坐标 */  
            }           
            else  
            {  
                put(n + 1); /* 否则继续摆放下一个皇后 */  
            }  
        }  
    }  
}  
   
int main()  
{  
    put(0); /* 从横坐标为0开始依次尝试 */  
    printf("%d", sum);  
    return 0;  
} 
