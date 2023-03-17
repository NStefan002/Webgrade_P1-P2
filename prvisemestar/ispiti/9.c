#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, cpn, s;
    while(scanf("%d", &n)!=EOF) {
        cpn=(n<0)? -n:n;
        s=0;
        while(cpn) {
            cpn/=10;
            s+=cpn%10;
        }
        if(abs(n%10)>s) 
            printf("%d ", n);
    }
    printf("\n");
}
