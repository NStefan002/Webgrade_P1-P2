#include <stdio.h>
#include <stdlib.h>
#define MAX_IME 21
#define MAX 100


typedef struct{
    char naziv[MAX_IME];
    double cena;
    char tip;
} PROIZVOD;

void opcija_pretrage(PROIZVOD proizvodi[], int n, char opcija) {
    int i, r=0;
    if(opcija=='r') {
        int a, b;
        scanf("%d %d", &a, &b);
        for(i=0; i<n; i++) {
            if(proizvodi[i].cena>=a && proizvodi[i].cena<=b) {
                printf("%s\n", proizvodi[i].naziv);
                r++;
            }
        }
    }
    else {
        char c;
        scanf(" %c", &c);
        if(c!='i' && c!='h') {
            printf("-1\n");
            exit(EXIT_FAILURE);
        }
        for(i=0; i<n; i++) {
            if(proizvodi[i].tip==c) {
                printf("%s\n", proizvodi[i].naziv);
                r++;
            }
        }
    }
    if(r==0) 
        printf("0\n");
}

int main() {
    int n;
    PROIZVOD proizvodi[MAX];
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    int i;
    for(i=0; i<n; i++) {
        scanf("%s %lf %c", proizvodi[i].naziv, &proizvodi[i].cena, &proizvodi[i].tip);
        if(proizvodi[i].cena<=0 || (proizvodi[i].tip!='i' && proizvodi[i].tip!='h')) {
            printf("-1\n");
            return 1;
        }
    }
    char opcija;
    scanf(" %c", &opcija);
//     printf("opcija %c\n", opcija);
    if(opcija!='r' && opcija!='t') {
        printf("-1\n");
        return 1;
    }
    opcija_pretrage(proizvodi,n,opcija);
}
