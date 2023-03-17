#include <stdio.h>

int main() {
    int x,p;
    scanf("%d",&x);
    (x==x/100+(x/10%10)*10+(x%10)*100)?(p=1):(p=0);
    printf("%d",p);
}
