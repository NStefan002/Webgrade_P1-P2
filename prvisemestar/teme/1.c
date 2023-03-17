#include <stdio.h>

int main() {
    int a,b,c,p;
    scanf("%d %d %d", &a, &b, &c);
    // p=a a=b b=c c=p
    p=a;
    a=b;
    b=c;
    c=p;
    printf("%d %d %d", a,b,c);
}
