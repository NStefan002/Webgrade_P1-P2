#include <stdio.h>

unsigned int apsolutnavrednost(int x);

int main() {
    int n;
    printf("Unesite broj: ");
    scanf("%d", &n);
    printf("Apsolutna vrednost: %d\n", apsolutnavrednost(n));
}

unsigned int apsolutnavrednost(int x) {
    x = x<0? -x : x;
    return x;
}
