#include <stdio.h>

int main() {
    int n, h, j;
    scanf("%d", &n);
    while(n!=0) {
        if(!(n/1000>=1 && n/1000<=9)) {
            puts("-1");
            return 1;
        }
        if((n/1000)%2==0 && (n%10)%2==0) { 
            h=n/1000;
            j=n%10;
            n=(n%1000)/10;
            n=n*10 + h + 1000*j;
        }
        else 
            n=(n%1000)/10;
        printf("%d\n", n);
        scanf("%d", &n);
    }
    return 0;
}
