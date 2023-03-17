#include <stdio.h>

int main() {
    int a,b,c,d,r;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    r=1;
    if (a<0) 
        r*=a;
    if (b<0) 
        r*=b;
    if (c<0) 
        r*=c;
    if (d<0) 
        r*=d;
    printf("%d",r);
    
}
