#include <stdio.h>

int main() {
    int n, cpn, br_cifara, zbir_cifara;
    while(scanf("%d", &n)!=EOF) {
        cpn=n;
        br_cifara=0;
        zbir_cifara=0;
        while(cpn) {
            zbir_cifara+=cpn%10;
            cpn/=10;
            br_cifara++;
        }
        if(zbir_cifara%2==0 || br_cifara%2==0)
            printf("%d ", n);
    }
    printf("\n");
}
