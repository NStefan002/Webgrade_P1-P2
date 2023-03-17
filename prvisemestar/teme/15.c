#include <stdio.h>
#include <stdlib.h>

int main() {
    int x,j,d,s,h,max,pmax;
    scanf("%d", &x);
    if ((x/1000>9)||(x/1000<-9)||(x/1000==0)) {
        printf("-1\n");
        return 1;
    }
    j=abs(x%10);
    d=abs(x%100/10);
    s=abs(x/100%10);
    h=abs(x/1000);
    max=j; pmax=1;
    if (max<d) {
    max=d;
    pmax=10; }
    if (max<s) {
        max=s;
        pmax=100; }
    if (max<h) {
        max=h;
        pmax=1000; }
    if (x<0) printf("%d\n", x+max*pmax-(max-1)*pmax);
    else printf("%d\n", x-max*pmax+(max-1)*pmax);
}
