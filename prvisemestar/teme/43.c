#include <stdio.h>
#define MAX 50

void ucitaj(int matrica[][MAX], int dimenzija) {
    int i, j;
    for(i=0; i<dimenzija; i++) 
        for(j=0; j<dimenzija; j++) 
            scanf("%d", &matrica[i][j]);
}

int max_elem(int matrica[][MAX], int dimenzija) {
    int i, j;
    int max=matrica[0][0];
    for(i=0; i<dimenzija; i++) 
        for(j=0; j<dimenzija; j++) {
            if(i==0 || i==dimenzija-1 || j==0 || j==dimenzija-1)
                if(max<matrica[i][j])
                    max=matrica[i][j];
        }
    return max;
}

int main() {
    int n, m[MAX][MAX];
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    ucitaj(m,n);
    printf("%d\n", max_elem(m,n));
}
