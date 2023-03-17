#include <stdio.h>
#define MAX 100

int main() {
    int n, a[MAX];
    float b[MAX];
    scanf("%d", &n);
    if (n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    int i;
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    if (n==1) {
        b[0]=a[0];
        printf("%d", b[0]);
        return 0;
    }
    for (i=0; i<n; i++) {
        if (i==0) b[i]=a[n-1]+a[i]+a[i+1];
        else if (i==n-1) b[i]=a[i-1]+a[i]+a[0];
        else b[i]=a[i-1]+a[i]+a[i+1];
            printf("%.2f ", b[i]/3);
    }
}
