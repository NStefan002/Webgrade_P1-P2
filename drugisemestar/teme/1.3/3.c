#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_IME 64

void greska();

int main() {
    int k, n;
    char ime[MAX_IME];
    scanf("%d%s", &k, ime);
    if(k <= 0)
        greska();

    FILE* f;
    f = fopen(ime, "r");
    if(NULL == f) 
        greska();
    
    fscanf(f, "%d", &n);
    if(n < 0)
        greska();

    int i, br, brojac = 0;
    for(i = 0; i < n; i++) {
        fscanf(f, "%d", &br);
        if(abs(br) / pow(10, k-1) <= 9 && abs(br) / pow(10, k-1) >= 1) 
            brojac++;
    }

    printf("%d\n", brojac);

    fclose(f);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}