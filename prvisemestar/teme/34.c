#include <stdio.h>
#define MAX 100

int main() {
    int n, a[MAX], i;
    float b[MAX];
    scanf("%d", &n);
    if (n<=0 || n>MAX) {
        puts("-1");
        return 1;
    }
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    if(n>=2) {
        for(i=0; i<n; i++) {
            if(i==0)
                b[i]=1.0*(a[n-1]+a[0]+a[1])/3;
            else
            if(i==n-1)
                b[i]=1.0*(a[n-2]+a[n-1]+a[0])/3;
            else b[i]=1.0*(a[i-1]+a[i]+a[i+1])/3;
        }
    }
    else
        if(n==1) 
        b[0]=a[0];
    for(i=0; i<n; i++) {
        printf("%.2f ", b[i]);
    }
    return 0;
}
