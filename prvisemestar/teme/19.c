#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n<=0) {
        printf("-1\n");
        return 1;
    }
    if (n>20) {
        printf("-1\n");
        return 1;
    }
    if (n%2==0) {
    long long int p=1; 
    for(int i=2; i<n+1; i+=2)
        p*=i;
    printf("%lld\n",p);
    }
    else {
    long long int p=1; 
    for(int i=1; i<n+1; i+=2)
        p*=i;
    printf("%lld\n",p);
    }
}
