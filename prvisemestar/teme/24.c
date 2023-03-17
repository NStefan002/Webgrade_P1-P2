#include <stdio.h>

int main() {
    int n, i, r=1;
    float a1, a2, q;
    scanf("%d", &n);
    if (n<=1) {
        printf("-1");
        return 1;
    }
    scanf("%f", &a1);
    scanf("%f", &a2);
    q=a2/a1;
    for (i=2; i<n; i++) {
        a1=a2;
        scanf("%f", &a2);
        if (a2/a1==q) r*=1;
        else r*=0;
    }
    if (r) printf("1");
    else printf("0");
    return 0;
}
