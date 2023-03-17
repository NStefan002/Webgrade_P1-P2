#include <stdio.h>

int main() {
    char a,b,c,d,e;
    scanf("%c%c%c%c%c", &a, &b, &c, &d, &e);
        int s=0;
        if (a>='0' && a<='9')
            s+=a;
        if (b>='0' && b<='9')
            s+=b;
        if (c>='0' && c<='9')
            s+=c;
        if (d>='0' && d<='9')
            s+=d;
        if (e>='0' && e<='9')
            s+=e;
    printf ("%d", s);
}
