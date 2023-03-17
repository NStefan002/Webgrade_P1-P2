#include <stdio.h>
#include <stdlib.h>

int main() {
    int k,l,m,n;
    scanf("%d %d %d %d", &k, &l, &m, &n);
    if ((k<1)||(k>8)||(l<1)||(l>8)||(m<1)||(m>8)||(n<1)||(n>8)||((k==m)&&(l==n))) {
        printf("-1");
        return 1;
    }
    // da li su polja (k,l) i (m,n) iste boje
    if ((abs(k-m)+abs(l-n))%2==0) printf("Polja su iste boje.\n");
    else printf("Polja su razlicite boje.\n");
    // da li kraljica sa (k,l) ugrozava polje (m,n)
    if (((abs(k-m)+abs(l-n))%2==0)||(k==m)||(l==m)) printf("Kraljica sa (%d,%d) ugrozava polje (%d,%d).\n", k,l,m,n);
    else printf("Kraljica sa (%d,%d) ne ugrozava polje (%d,%d).\n", k,l,m,n);
    // da li konj sa (k,l) ugrozava polje (m,n)
    if (((abs(k-m)==1)&&(abs(l-n)==2))||((abs(k-m)==2)&&(abs(l-n)==1))) printf("Konj sa (%d,%d) ugrozava polje (%d,%d).\n",k,l,m,n);
    else printf("Konj sa (%d,%d) ne ugrozava polje (%d,%d).\n",k,l,m,n);
}
