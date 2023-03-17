#include <stdio.h>

int main() {
    int x,j,d,s,h,p;
    scanf("%d", &x);
    if (x<0) x=-x;
    if ((x/1000>9)||(x/1000<1)) {
        printf("-1\n");
        return 1;
    }
    j=x%10;
    d=x%100/10;
    s=x/100%10;
    h=x/1000;
    p=0;
    if (j%2==0) p+=1;
    if (d%2==1) p+=1;
    if (s%2==0) p+=1;
    if (h%2==1) p+=1;
    printf("%d\n",p);
}
