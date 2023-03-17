#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d/%d-%d", &a, &b, &c);
    switch (a) {
        case(64):
        case(65):
        case(66):
            printf("%d\n", (b/1000)*(b/1000)+(b/100%10)*(b/100%10)+(b/10%10)*(b/10%10)+(b%10)*(b%10)+(c/100)*(c/100)+(c/10%10)*(c/10%10)+(c%10)*(c%10));
            break;
        case(60):
        case(61):
        case(68):
            printf("%d\n", b/1000+b/100%10+b/10%10+b%10);
            break;
        case(62):
        case(63):
        case(69):
            printf("%d\n", c/100%10+c/10%10+c%10);
            break;
    }
    
}
