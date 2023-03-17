#include <stdio.h>
#include <math.h>

int main() {
    int n, cpn, br, zadnja;
    while(scanf("%d", &n)!=EOF) {
        br=0;
        if(n<0) {
            printf("-1\n");
            return 1;
        }
        cpn=n;
        while(cpn>=10) {
            cpn/=10;
            br++;
        }
        if(br==0)
            printf("%d\n", n);
        else {
            zadnja=n%10;
            n-=zadnja;
            n%=(int)pow(10,br);
            n+=zadnja*pow(10, br)+cpn;
            printf("%d\n", n);
        }
    }
}
