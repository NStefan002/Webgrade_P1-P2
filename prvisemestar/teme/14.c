#include <stdio.h>

int main() {
    char c;
    scanf("%c",&c);
    if (c%2==0)
        printf("%c\n", c+1);
    else printf("%c\n", c-1);
}
