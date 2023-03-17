#include <stdio.h>

int zbir(int x);

int main() {
    int x;
    scanf("%d", &x);
    printf("%d", zbir(x));
}

int zbir(int x) {
    x= x<0? -x : x;
    int r;
    if (x<10) r=2*x;
    else r=x%10;
    while (x>0) {
        x/=10;
        if(x<10) r+=x;
    }
    return r;
}
