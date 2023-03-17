#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, a1, a2;
    scanf("%d", &n);
    n=abs(n);
    int cpn=n;
    for (i=0; cpn>0; i++) {
        cpn/=10;
    }
    if (i%2==1) {
        a1=(n/(int)pow(10, i/2)) % 10;
        printf("%.1lf\n", (double)a1);
    }
    else {
        a1=(n/(int)pow(10, i/2)) % 10;
        a2=(n/(int)pow(10, i/2-1)) % 10;
        printf("%.1lf\n", (double)(a1+a2)/2);
    }
}

// 1234 
