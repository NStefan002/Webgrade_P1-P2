#include <stdio.h>
#include <stdlib.h>

#define MAX 21

// definisanje strukture za rad sa polinomima
typedef struct Polinom
{
    char ime[MAX];
    unsigned n;
    float* koeficijenti;
    float vrednost;
}Polinom;

void greska();
Polinom* ucitaj_niz(int dim, FILE* f, float x);
void ispis_i_oslobodi_niz(Polinom* niz, int dim);

float vrednost_polinoma_u_tacki(float koef[], int n, float x);
void razmeni(Polinom* niz, int i, int j);
int particionisanje(Polinom* niz, int l, int d);
void quick_sort(Polinom* niz, int l, int d);

int main(int argc, const char* argv[])
{
    // provera broja argumenata
    if (argc != 2)
    {
        greska();
    }
    float x = atof(argv[1]);

    // otvaranje datoteke koja sadrzi informacije o polinomima
    FILE* ulaz = fopen("polinomi.txt", "r");
    if (NULL == ulaz)
    {
        greska();
    }

    // ucitavanje niza polinoma
    int br_polinoma;
    fscanf(ulaz, "%d", &br_polinoma);

    Polinom* niz;
    niz = ucitaj_niz(br_polinoma, ulaz, x);

    // sortiranje pomocu implementiranih f-ja
        // ucitavanje tacke iz komandne linije
    quick_sort(niz, 0, br_polinoma-1);

    // ispisivanje niza i oslobadjanje memorije koje zauzimaju nizovi koeficijenata
    ispis_i_oslobodi_niz(niz, br_polinoma);

    // zatvaranje datoteke i oslobadjanje memorije
    fclose(ulaz);    
    free(niz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

Polinom* ucitaj_niz(int dim, FILE* f, float x)
{
    Polinom* niz = malloc(dim * sizeof(Polinom));
    if (NULL == niz)
    {
        greska();
    }
    
    for (int i = 0; i < dim; i++)
    {
        fscanf(f, "%s%u", niz[i].ime, &niz[i].n);
        
        // ucitvanje koeficijenata na osnovu niz[i].n
        niz[i].koeficijenti = malloc(niz[i].n * sizeof(float));
        if (NULL == niz[i].koeficijenti)
        {
            greska();
        }
        
        for (unsigned j = 0; j < niz[i].n; j++)
        {
            fscanf(f, "%f", &niz[i].koeficijenti[j]);
        }

        niz[i].vrednost = vrednost_polinoma_u_tacki(niz[i].koeficijenti, niz[i].n, x);
    }
    
    return niz;
}

void ispis_i_oslobodi_niz(Polinom* niz, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("%s %.2f\n", niz[i].ime, niz[i].vrednost);
        
        free(niz[i].koeficijenti);
    }
}

float vrednost_polinoma_u_tacki(float koef[], int n, float x)
{
    float rez = 0;
    for (int i = n-1; i >= 0; i--)
    {
        // racunanje vrednosti polinoma u tacki x pomocu Hornerove seme
        rez *= x;
        rez += koef[i];
    }
    
    return rez;
}

void razmeni(Polinom* niz, int i, int j)
{
    // zamena mesta dva clana niza
    Polinom tmp = niz[i];
    niz[i] = niz[j];
    niz[j] = tmp;
}

int particionisanje(Polinom* niz, int l, int d)
{
    int pivot = l;
    for (int i = l + 1; i <= d; i++)
    {
        if (niz[i].vrednost > niz[l].vrednost)
        {
            pivot++;
            razmeni(niz, i, pivot);
        }
    }
    razmeni(niz, l, pivot);
    return pivot;
}

void quick_sort(Polinom* niz, int l, int d)
{
    if (l >= d)
    {
        return;
    }

    int pivot = particionisanje(niz, l, d);
    
    quick_sort(niz, pivot+1, d);
    quick_sort(niz, l, pivot-1);
}