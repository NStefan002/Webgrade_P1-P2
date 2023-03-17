#include <stdio.h>
#include <ctype.h>

int main() {
    char op, a;
    int c=0, m=0;
    scanf("%c", &op);
    for (int i=0; i<=5; i++) {
        scanf("%c", &a);
        if (a>='0'&& a<='9') {
            c+=a-'0';
        }
        if (islower(a)) {
            m+=1;
        }
    }
    switch(op) {
        case('C'):
            printf("%d\n", c);
            break;
        case('M'):
            printf("%d\n", m);
            break;
        default: printf("-1\n");
    }
    return 0;
}
