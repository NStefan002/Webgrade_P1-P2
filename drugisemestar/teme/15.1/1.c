#include <stdio.h>
#include <stdlib.h>

#define KORAK 10

typedef struct _tacka
{
    double x;
    double y;
}Tacka;

void greska();
Tacka* ucitaj(FILE* f, int* n);
Tacka* formiraj_max_niz(Tacka* niz, int n, int* dim);
void ispisi(Tacka* niz, int n);

int jeste_maksimalna(Tacka* niz, int n, Tacka tacka);
int uporedi(const void* a, const void* b);

int main(int argc, const char* argv[])
{
    if (argc != 2)
    {
        greska();
    }
    FILE* f = fopen(argv[1], "r");
    if (NULL == f)
    {
        greska();
    }
    
    int n;
    Tacka* niz = ucitaj(f, &n);
    
    int m;
    Tacka* niz_maksimalnih = formiraj_max_niz(niz, n, &m);

    qsort(niz_maksimalnih, m, sizeof(Tacka), &uporedi);
    ispisi(niz_maksimalnih, m);

    fclose(f);
    free(niz);
    free(niz_maksimalnih);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

Tacka* ucitaj(FILE* f, int* n)
{
    Tacka* niz = malloc(KORAK * sizeof(Tacka));
    if (NULL == niz)
    {
        greska();
    }
    
    int i = 0;
    while (fscanf(f, "%lf %lf", &niz[i].x, &niz[i].y) != EOF)
    {
        i++;
        if (i % KORAK == 0)
        {
            Tacka* tmp = realloc(niz, (i + KORAK) * sizeof(Tacka));
            if (NULL == tmp)
            {
                free(niz);
                greska();
            }
            niz = tmp;
        }
    }

    *n = i;
    return niz;
}

int jeste_maksimalna(Tacka* niz, int n, Tacka tacka)
{
    for (int i = 0; i < n; i++)
    {
        if ((niz[i].x > tacka.x && niz[i].y > tacka.y) || (niz[i].x >= tacka.x && niz[i].y > tacka.y) || (niz[i].x > tacka.x && niz[i].y >= tacka.y))
        {
            return 0;
        }
    }
    
    return 1;
}

Tacka* formiraj_max_niz(Tacka* niz, int n, int* dim)
{
    Tacka* novi_niz = malloc(n * sizeof(Tacka));
    if (NULL == novi_niz)
    {
        free(niz);
        greska();
    }
    
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (jeste_maksimalna(niz, n, niz[i]))
        {
            novi_niz[k] = niz[i];
            k++;
        }
    }
    
    *dim = k;
    return novi_niz;
}

void ispisi(Tacka* niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf %.2lf\n", niz[i].x, niz[i].y);
    }
}

int uporedi(const void* a, const void* b)
{
    double ax = ((Tacka*)a)->x;
    double bx = ((Tacka*)b)->x;

    if (ax > bx)
    {
        return -1;
    }
    else if (ax < bx)
    {
        return 1;
    }
    
    return 0;
}