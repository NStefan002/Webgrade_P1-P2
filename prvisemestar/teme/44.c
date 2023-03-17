#include <stdio.h>
#define MAX 50

void ucitaj(int matrica[][MAX], int dimenzija) {
    int i, j;
    for(i=0; i<dimenzija; i++) 
        for(j=0; j<dimenzija; j++) 
            scanf("%d", &matrica[i][j]);
}

int min_elem(int matrica[][MAX], int dimenzija, int indeks_vrste) {
    int j;
    int min=matrica[indeks_vrste][0];
    for(j=1; j<dimenzija; j++) 
        if(min>matrica[indeks_vrste][j]) 
            min=matrica[indeks_vrste][j];
    return min;
}

int main() {
    int n, m[MAX][MAX];
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    ucitaj(m,n);
    int indeks;
    scanf("%d", &indeks);
    if(indeks<0 || indeks>=n) {
        printf("-1\n");
        return 1;
    }
    printf("%d\n", min_elem(m,n,indeks));
}
