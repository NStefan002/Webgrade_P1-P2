#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska();
int f14(int x);

int main()
{
    int n;
    scanf("%d", &n);
    int znak = (n < 0)? -1: 1;

    printf("%d\n", znak * f14(znak * n));

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int f14(int x)
{
    if(x <= 99) 
        return x;
    
    int c1, c2, c3;
    c1 = x % 10;
    c2 = (x % 100) / 10;
    c3 = (x % 1000) / 100;

    int novi_broj = f14(x/10);
    
    if(c2 == c1 + c3)
        novi_broj /= 10;

    return novi_broj*10 + x%10;  
}

/* 1) 12121     1 2 1           112     11*10 + 1 = 111
   2) 1212      2 1 2           11      11*10 + 2 = 112
   3) 121       1 2 1           12      1*10 + 1 = 11
   4) 12 
   */