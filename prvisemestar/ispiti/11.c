#include <stdio.h>
#define MAX 100

void ucitaj(int matrica[][MAX], int dimenzija) {
    int i, j;
    for(i=0; i<dimenzija; i++) 
        for(j=0; j<dimenzija; j++) 
            scanf("%d", &matrica[i][j]);
}

int magicni_kvadrat(int matrica[][MAX], int dimenzija) {
    int i, j, s[MAX]={0};
    for(i=0; i<dimenzija; i++) 
        for(j=0; j<dimenzija; j++) 
            s[i]+=matrica[i][j];
    int r=1;
    for(i=1; i<dimenzija; i++)
        if(s[0]==s[i]) 
            r*=1;
        else 
            r*=0;
    return r;
}

int main() {
    int n, m[MAX][MAX];
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    ucitaj(m,n);
    if(magicni_kvadrat(m,n)) {
        int i, j, suma=0;
        for(i=0; i<n; i++) 
            for(j=0; j<n; j++) 
                suma+=m[i][j];
        printf("%d\n", suma);
    }
    else 
        printf("0\n");
    
}
