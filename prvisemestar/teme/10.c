#include <stdio.h>

int main(){
    long long int x,d,l;
    scanf("%lld",&x);
    // 12345 12 3 45
    d=x%100;
    l=x/1000;
    printf("%lld", l*100+d);
}
