#include <stdio.h>

int main() {
    char c;
    int a,b;
    scanf("%c %d %d");
    if ((c!='p')||(c!='n')||(a%100>9)||(a%100<1)||(b%100>9)||(b%100<1)) {
        printf("-1");
        return 1;
    }
    printf("brv");
}
