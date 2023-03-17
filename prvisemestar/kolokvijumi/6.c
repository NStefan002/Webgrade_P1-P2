#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, s, max, cpx;
    scanf("%d", &n);
    if (n<=0) {
        printf("-1\n");
        return 1;
    }
    scanf("%d", &x);
    x=abs(x);
    max=x/100%10;
    cpx=x;
    for(int i=1; i<n; i++){
        scanf("%d", &x);
        x=abs(x);
        if (x<1000 || x>9999){
            printf("-1\n");
            return 1;
        }
       s=x/100%10;
       if(s>=max) {
           max=s;
           cpx=x;
        }
    }
    printf("%d\n", cpx/1000+cpx/100%10+cpx/10%10+cpx%10);
}
