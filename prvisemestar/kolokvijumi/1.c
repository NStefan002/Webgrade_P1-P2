#include <stdio.h>

int main() {
    int a, b, r;
    char c;
    scanf("%c%d%d", &c, &a, &b);
    if ((c!='p' && c!='n')
    (a<100 a>999)(b<100 b>999)) {
        printf("-1");
        return 1;
    }
    if (c=='p') {
        r=a/10%10+b/10%10;
        printf("%d", r);
        return 0;
    }
    if (c=='n') {
        r=a%10+a/100+b%10+b/100;
        printf("%d", r);
        return 0;
    }
}
