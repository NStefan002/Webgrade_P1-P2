#include <stdio.h>

void romb(int n);

int main() {
    int n;
    printf("Unesite broj n: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("Greska: pogresna dimenzija!\n");
        return 1;
    }
    romb(n);
}

void romb(int n) {
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=0; j<n-i;j++) printf(" ");
        for (j=0; j<n;j++) printf("*");
        printf("\n");
    }
}
