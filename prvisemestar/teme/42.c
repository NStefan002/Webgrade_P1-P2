#include <stdio.h>
#define MAX 50

void ucitaj_i_saberi(int matrica[][MAX], int dimenzija, int* suma) {
    int i, j;
    for(i=0; i<dimenzija; i++) 
        for(j=0; j<dimenzija; j++) {
            scanf("%d", &matrica[i][j]);
            if(j%2==0) 
                *suma+=matrica[i][j];
        }
}

int main() {
    int n, m[MAX][MAX];
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    int s=0;
    ucitaj_i_saberi(m,n,&s);
    printf("%d\n", s);
}
