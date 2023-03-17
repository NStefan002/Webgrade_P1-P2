#include <stdio.h>

int main() {
    int n, a1, a2, a3, i, r=1;
    scanf("%d", &n);
    if (n<=0) {
        printf("-1");
        return 1;
    }
    if (n==1) {
            scanf("%d", &a1);
            printf("1");
            return 0;
    }
    scanf("%d", &a1);
    scanf("%d", &a2);
    if (a1==a2) {
        printf("0");
        return 0;
    }
    for (i=2; i<n; i++) {
        scanf("%d", &a3);
        if (a1<a2) {
        if (a2>a3) r*=1;
        else r*=0;
        } else {
            if (a2<a3) r*=1;
            else r*=0;
        }
        a1=a2; a2=a3;
    }
    if (r) printf("1");
    else printf("0");
    return 0;
}
