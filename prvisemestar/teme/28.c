#include <stdio.h>

int main() {
    int m, n;
    double cl=1, r=1;
    scanf("%d%d", &m, &n);
    if (n<0) {
        printf("-1\n");
        return 1;
    }
    for (int i=2; i<=2*n; i+=2) {
        cl*=1.0*m*m/(i*(i-1));
        cl*=-1;
        r+=cl;
    }
    printf("%.4lf\n", r);
}
