#include <stdio.h>
#include <stdlib.h>

#define MAX 21

typedef struct Proizvod
{
    char naziv[MAX];
    float cena;
    float kolicina;
    float ukupno;
}Proizvod;

void greska();
Proizvod* ucitaj_niz(int n, FILE* f);
void ispisi_niz(Proizvod* niz, int n);
void razmeni(Proizvod* niz, int i, int j);
int particionisanje(Proizvod* niz, int l, int d);
void quick_sort(Proizvod* niz, int l, int d);
int uporedi(const void* px, const void* py);

int main()
{
    // otvaranje datoteke
    FILE* f = fopen("proizvodi.txt", "r");
    if(NULL == f)
        greska();

    Proizvod* niz;
    int n;
    fscanf(f, "%d", &n);

    niz = ucitaj_niz(n, f);   
    // qsort(niz, n, sizeof(Proizvod), &uporedi);
    quick_sort(niz, 0, n-1);
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

Proizvod* ucitaj_niz(int n, FILE* f)
{
    Proizvod* p = malloc(n * sizeof(Proizvod));
    if(NULL == p)
        greska();
    
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%s%f%f", p[i].naziv, &p[i].cena, &p[i].kolicina);
        p[i].ukupno = p[i].cena * p[i].kolicina;
    }
    
    return p;
}

void ispisi_niz(Proizvod* niz, int n)
{
    if(n == 0)
        return;
    
    printf("%s %.2f %.2f %.2f\n", niz->naziv, niz->cena, niz->kolicina, niz->ukupno);
    ispisi_niz(niz+1, n-1);
}

void razmeni(Proizvod* niz, int i, int j)
{
    Proizvod tmp;
    tmp = niz[i];
    niz[i] = niz[j];
    niz[j] = tmp;
}

int particionisanje(Proizvod* niz, int l, int d)
{
    int pivot = l;
    int i;
    for(i = l + 1; i <= d; i++)
    {
        if(niz[i].ukupno > niz[l].ukupno)
        {
            pivot++;
            razmeni(niz, pivot, i);
        }
    }
    razmeni(niz, l, pivot);
    return pivot;
}

void quick_sort(Proizvod* niz, int l, int d)
{
    if(l >= d)
        return;
    
    int poz_pivota = particionisanje(niz, l, d);

    quick_sort(niz, l, poz_pivota - 1);
    quick_sort(niz, poz_pivota + 1, d);
}

int uporedi(const void* px, const void* py)
{
    float x, y;
    x = ((Proizvod*)px)->ukupno;
    y = ((Proizvod*)py)->ukupno;
    if(x == y)
        return 0;
    if(x > y)
        return -1;
    return 1;
}