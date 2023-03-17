#include <stdio.h>

int main() {
    int x,j,d,s,h;
    scanf("%d",&x);
    if ((x/1000==0) || (x/1000>=10)) {
        printf("-1");
        return 1};
    else j=x%10;
         d=x%100/10;
         s=x/100%10;
         h=x/1000;
            
    
}
