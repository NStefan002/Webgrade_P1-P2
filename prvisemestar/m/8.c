#include <stdio.h>

int zbir_delilaca(int n);

int main() {
    int k;
    printf("Unesite broj k: ");
    scanf("%d", &k);
    if (k<1) {
        printf("Greska: pogresan unos!\n");
        return 1;
    }
    zbir_delilaca(k);
}

int zbir_delilaca(int n) {
    int r;
    for (int i=1; i<=n; i++) {
        r=0;
        for (int j=1; j<=i; j++){
            if (i%j==0) {
            r+=j;
            }
        }
            printf("%d ", r);
    }
    return r;
}
