#include <stdio.h>

int main() {
    double a,b,h;
    scanf("%lf %lf %lf", &a, &b, &h);
    printf("%.2lf", h*(a+b)/2);
}
