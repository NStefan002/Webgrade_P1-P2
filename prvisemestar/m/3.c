#include <stdio.h>

float razlomljeni_deo(float x);

float main() {
    float n;
    printf("Unesite broj: ");
    scanf("%f", &n);
    printf("Razlomljeni deo: %f", razlomljeni_deo(n));
}

float razlomljeni_deo(float x) {
    x = x<0 ? -x : x;
    int cpx=x;
    x-=cpx;
    return x;
}
