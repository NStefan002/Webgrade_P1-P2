#include <stdio.h>

int main() {
    unsigned n, i, j;
    scanf("%u", &n);
    if (n<=0 || n>=100) {
        printf("-1");
        return 1;
    }
    for (i=1; i<=n; i++) {
        printf("~");
        for (j=i; j>=1; j--){
            if (j%2==1) printf("1");
            else printf("0");
        }
        printf("~\n");
    }
}
