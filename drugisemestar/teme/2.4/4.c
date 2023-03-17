#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x;
    int y;
    int z;
}VEKTOR;

void greska();

int main() {
    // otvaranje datoteke
    FILE* f;
    f = fopen("vektori.txt", "r");
    if(NULL == f)
        greska();

    // alokacija memorije za niz vektora
    int n;
    fscanf(f, "%d", &n);
    if(n <= 0)
        greska();
    VEKTOR* v;
    v = (VEKTOR*)malloc(n * sizeof(VEKTOR));
    if(NULL == v)
        greska();

    // ucitavanje iz datoteke
    int max_i, i;
    float duzina, max = 0;
    for(i = 0; i < n; i++) {
        fscanf(f, "%d%d%d", &v[i].x, &v[i].y, &v[i].z);
        duzina = sqrt(v[i].x*v[i].x + v[i].y*v[i].y + v[i].z*v[i].z);
        if(max < duzina) {
            max = duzina;
            max_i = i;
        }
    }
    // ispisivanje rezultata
    printf("%d %d %d\n", v[max_i].x, v[max_i].y, v[max_i].z);

    // zatvaranje datoteke i oslobadjanje memorije
    fclose(f);
    free(v);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}