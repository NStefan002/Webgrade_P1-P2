#include <stdio.h>
#include <math.h>

int main() {
    double r;
    // V=4/3 r^3  * PI
    scanf("%lf",&r);
    printf("%.3lf", 4*r*r*r*M_PI/3);
}
