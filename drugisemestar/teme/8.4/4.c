#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define KORAK 10

typedef struct Tacka
{
    double x;
    double y;
    double r;   // rastojanje od zadate tacke
}Tacka;

void greska();
double sqr(double x);
void ispisi_niz(Tacka* niz, int n);

void razmeni(Tacka* niz, int i, int j);
int particionisanje(Tacka* niz, int l, int d);
void quick_sort(Tacka* niz, int l, int d);

int main()
{
    Tacka a;
    scanf("%lf%lf", &a.x, &a.y);

    Tacka* niz;
    FILE* f = fopen("tacke.txt", "r");
    if(NULL == f)
        greska();

    int alocirano, i, n;
    alocirano = KORAK;
    niz = malloc(alocirano * sizeof(Tacka));
    if(NULL == niz)
        greska();

    i = 0;
    while (fscanf(f, "%lf%lf", &niz[i].x, &niz[i].y) == 2)
    {
        niz[i].r = sqrt(sqr(niz[i].x - a.x) + sqr(niz[i].y - a.y));
        i++;
        if(i == alocirano)
        {
            alocirano += KORAK;
            niz = realloc(niz, alocirano * sizeof(Tacka));
            if(NULL == niz)
                greska();
        }
    }
    n = i;

    // ispisi_niz(niz, n);
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

double sqr(double x)
{
    return (x)*(x);
}

void ispisi_niz(Tacka* niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf %.2lf %.2lf\n", niz[i].x, niz[i].y, niz[i].r);
    }
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
        if (niz[i].r < niz[l].r)
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

    int poz_piv = particionisanje(niz, l, d);

    quick_sort(niz, l, poz_piv-1);
    quick_sort(niz, poz_piv+1, d);
}