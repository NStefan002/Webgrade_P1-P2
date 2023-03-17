#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// definisanje strukture za cuvanje podataka o duzima
typedef struct Duz
{
    float Ax;
    float Ay;
    float Bx;
    float By;
    float d;
}Duz;

void greska();
void ucitaj_niz(Duz* niz, int n, FILE* f);
void ispisi_niz(Duz* niz, int n);
float sqr(float x);
int uporedi(const void* px, const void *py);

int main()
{
    // otvaranje datoteke
    FILE* f = fopen("duzi.txt", "r");
    if(NULL == f)
        greska();

    Duz* niz;
    int n;
    fscanf(f, "%d", &n);
    niz = (Duz*)malloc(n * sizeof(Duz));
    if(NULL == niz)
        greska();
    
    ucitaj_niz(niz, n, f);
    qsort(niz, n, sizeof(Duz), &uporedi);
    ispisi_niz(niz, n);

    // zatvaranje datoteke i oslobadjanje memorije
    fclose(f);
    free(niz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

float sqr(float x)
{
    return (x) * (x);
}

void ucitaj_niz(Duz* niz, int n, FILE* f)
{
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%f%f%f%f", &niz[i].Ax, &niz[i].Ay, &niz[i].Bx, &niz[i].By);
        niz[i].d = sqrtf(sqr(niz[i].Ax - niz[i].Bx) + sqr(niz[i].Ay - niz[i].By));
    }
}

void ispisi_niz(Duz* niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2f %.2f %.2f %.2f %.2f\n", niz[i].Ax, niz[i].Ay, niz[i].Bx, niz[i].By, niz[i].d);
    }
}

int uporedi(const void* px, const void *py)
{
    float ret = (*(Duz*)py).d - (*(Duz*)px).d; 
    if(ret == 0.0)
        return 0;
    if(ret > 0)
        return 1;
    return -1;
}