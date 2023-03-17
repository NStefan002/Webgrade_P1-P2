#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n<=0) {
        printf("-1");
        return 1;
    }
    double s=0;
    for(int i=1; i<n+1; i++)
        s+=1.0/i;  
    printf("%.6lf", n/s);
}
