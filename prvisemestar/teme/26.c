#include <stdio.h>

int main() {
    int n, a1, a2, a3, i;
    scanf("%d", &n);
    if (n<=0) {
        printf("-1\n");
        return 1;
    }
    a1=0; a2=1;
    if (n==1) {
        printf("0\n");
        return 0;
    }
    if (n==2) {
        printf("1\n");
        return 0;
    }
    printf("%d ", a1);
    printf("%d ", a2);
    for (i=2; i<n; i++) {
        a3=a1+a2;
        printf("%d ", a3);
        a1=a2;
        a2=a3;
    }
    
}
