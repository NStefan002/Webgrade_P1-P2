#include <stdio.h>

int main() {
    int n, a, b, c, d, r;
    scanf("%d", &n);
    a=n/1000;
    b=n/100%10;
    c=n/10%10;
    d=n%10;
    r=n;
    if (a%2==0) r*=a;
    if (b%2==0) r*=b;
    if (c%2==0) r*=c;
    if (d%2==0) r*=d;
    printf("%d", r);
}
