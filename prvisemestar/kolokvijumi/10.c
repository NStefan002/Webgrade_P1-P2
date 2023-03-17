#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, r=0, g;
    scanf("%d", &n);
    if (n<=0) {
        printf("-1\n");
        return 1;
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        x=abs(x);
        if (x/1000<1 || x/1000>9) {
            g=1;
        }
        if (x%10>x/10%10 && x/10%10>x/100%10 && x/100%10>x/1000){
            r=x;
        }
    }
    if (g==1) {
        printf("-1\n");
        return 1;
    }
    if (r==0) {
        printf("0\n");
        return 0;
    }
    printf("%d\n", r%10);
}
