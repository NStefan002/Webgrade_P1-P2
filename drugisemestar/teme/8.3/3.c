#include <stdio.h>
#include <stdlib.h>

#define KORAK 10

typedef struct Tacka
{
    double x;
    double y;
}Tacka;

void greska();
void razmeni(Tacka* niz, int i, int j);
int particionisanje(Tacka* niz, int l, int d);
void quick_sort(Tacka* niz, int l, int d);
void ispisi_niz(Tacka* niz, int n);

int main(int argc, const char* argv[])
{
    if(argc != 2)
        greska();
    
    FILE* f = fopen(argv[1], "r");
    if(NULL == f)
        greska();
    
    int alocirano = KORAK;
    Tacka* niz = malloc(alocirano * sizeof(Tacka));
    if(NULL == niz)
        greska();
    int i = 0;
    while (fscanf(f, "%lf%lf", &niz[i].x, &niz[i].y) == 2)
    {
        i++;
        if(i == alocirano)
        {
            alocirano += KORAK;
            niz = realloc(niz, alocirano*sizeof(Tacka));
            if(NULL == niz)
                greska();
        }
    }
    
    int n = i;
    quick_sort(niz, 0, n-1);
    ispisi_niz(niz, n);

    fclose(f);
    free(niz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void razmeni(Tacka* niz, int i, int j)
{
    Tacka tmp;
    tmp = niz[i];
    niz[i] = niz[j];
    niz[j] = tmp;
}

int particionisanje(Tacka* niz, int l, int d)
{
    int pivot = l, i;

    for (i = l + 1; i <= d; i++)
    {
        if(niz[i].x < niz[l].x || (niz[i].x == niz[l].x && niz[i].y > niz[l].y))
        {
            pivot++;
            razmeni(niz, pivot, i);
        }
    }
    razmeni(niz, l, pivot);
    return pivot;
}

void quick_sort(Tacka* niz, int l, int d)
{
    if(l >= d)
        return;

    int pozicija_pivota = particionisanje(niz, l, d);

    quick_sort(niz, l, pozicija_pivota-1);
    quick_sort(niz, pozicija_pivota+1, d);
}

void ispisi_niz(Tacka* niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2f %.2f\n", niz[i].x, niz[i].y);
    }
}