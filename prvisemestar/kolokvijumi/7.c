#include <stdio.h>
#include <ctype.h>

int main() {
    char op, a;
    int c=1, v=0, b=0;
    scanf("%c", &op);
    for (int i=0; i<=5; i++) {
        scanf("%c", &a);
        if (a>='0'&& a<='9') {
            c*=a-'0';
            b++;
        }
        if (isupper(a)) {
            v++;
        }
    }
    switch(op) {
        case('C'):
            if (b==0) {
                printf("0\n");
                break;
            } else {
                printf("%d\n", c);
                break;
            }
        case('V'):
            printf("%d\n", v);
            break;
        default: printf("-1\n");
    }
    return 0;
}
