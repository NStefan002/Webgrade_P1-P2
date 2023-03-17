#include <stdio.h>
#include <stdlib.h>

void greska();
void sortirani_neopadajuce(int** a, int n);

int main()
{
    // otvaranje datoteke sa podacima o matricama
    FILE* mat = fopen("matrica.txt", "r");
    if(NULL == mat)
        greska();
    
    // ucitavanje matrice
    int dimenzija;
    int** matrica;

    fscanf(mat, "%d", &dimenzija);
    if(dimenzija <= 0)
        greska();
    
        // alokacija memorije za matricu
    matrica = (int**)malloc(dimenzija * sizeof(int*));
    if(NULL == matrica)
        greska();
    
    int i, j;
    for(i = 0; i < dimenzija; i++) {
        matrica[i] = (int*)malloc(dimenzija * sizeof(int));
        if(NULL == matrica[i])
            greska();
    }

        // ucitavanje elemenata matrice
    for(i = 0; i < dimenzija; i++) 
        for(j = 0; j < dimenzija; j++) 
            fscanf(mat, "%d", &matrica[i][j]);

    sortirani_neopadajuce(matrica, dimenzija);

    // zatvaranje datoteke, oslobadjanje memorije i izlazak iz programa
    fclose(mat);
    for(i = 0; i < dimenzija; i++)
        free(matrica[i]);
    free(matrica);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void sortirani_neopadajuce(int** a, int n)
{
    int i, j, p; // p - provera da li je uslov ispunjen 
    for(i = 0; i < n; i++) {
        p = 1;
        for(j = 1; j < n; j++) {
            if(a[i][j-1] > a[i][j])
                p = 0;
        }
        if(p)
            printf("%d\n", i);
    }
}