#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, min, d, cpx;
    scanf("%d", &n);
    if (n<=0) {
        printf("-1");
        return 1;
    }
    scanf("%d", &x);
    x=abs(x);
    if (x<10000 || x>99999) {
        printf("-1");
        return 1;
    }
    min=x/10%10;
    cpx=x;
    for(int i=1; i<n; i++){
        scanf("%d", &x);
        x=abs(x);
        if (x<10000 || x>99999) {
            printf("-1");
            return 1;
    }
        d=x/10%10;
        if (d<min){
            min=d; 
            cpx=x;
        }
    }
    printf("%d\n", (cpx/10000)*(cpx/1000%10)*(cpx/100%10)*(cpx/10%10)*(cpx%10));
        
    
}
