#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    if (n<0) {
        printf("-1");
        return 1;
    }
    int s=1, p=1, i=0;
    while(i<n) {
        p*=m;
        s+=p;
        i++;
    }
    printf("%d", s);
}
