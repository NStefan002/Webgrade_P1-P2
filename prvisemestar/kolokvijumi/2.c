#include <stdio.h>
#include <math.h>

int main() {
    int i, n;
    scanf("%d%d", &n, &i);
    if (i<=0 || n<0) {
        printf("-1\n");
        return 1;
    }
    n=n%(int)pow(10,i-1) + (n/(int)pow(10,i))*pow(10,i-1);
    printf("%d\n", n);
}
