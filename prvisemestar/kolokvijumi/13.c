#include <stdio.h>

int main() {
    int n, i, x, r=0;
    scanf("%d", &n);
    if (n<1) {
        printf("-1\n");
        return 1;
    }
    for(i=0; i<n; i++) {
        scanf("%d", &x);
        x= x<0 ? -x : x;
        if (x<100 || x>999) {
            printf("-1\n");
            return 1;
        }
        if (x/100>x/10%10 && x/10%10>x%10)
            r=x;
    }
    if (r==0) printf("%d\n", x);
    else printf("%d\n", r%10);
}
