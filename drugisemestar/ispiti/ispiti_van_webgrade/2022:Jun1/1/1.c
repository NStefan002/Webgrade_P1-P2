#include <stdio.h>
#include <stdlib.h>

#define MAX_IME_PREZIME 101
#define TRENUTNI_VEK 21
#define GODINA_U_VEKU 100
#define KORAK 10    // za alokaciju

typedef struct 
{
    char ime[MAX_IME_PREZIME];
    char prezime[MAX_IME_PREZIME];
    int godina_rodjenja;
} Naucnik;

void greska();
Naucnik *ucitaj_niz_naucnika(FILE *f, int *n);

int uporedi(const void *kljuc, const void *element);

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        greska();
    }

    FILE *dat = fopen(argv[1], "r");
    if (NULL == dat)
    {
        greska();
    }
    
    int v = atoi(argv[2]);
    if (v < 1 || v > TRENUTNI_VEK)
    {
        greska();
    }
    
    int br_naucnika;
    Naucnik *naucnici = ucitaj_niz_naucnika(dat, &br_naucnika);

    Naucnik *pronadjeni = bsearch(&v, naucnici, br_naucnika, sizeof(Naucnik), &uporedi);
    if (NULL == pronadjeni)
    {
        fclose(dat);
        free(naucnici);
        return 0;
    }
    
    int index_pronadjenog = pronadjeni - naucnici;
    
    int i = index_pronadjenog;
    while (naucnici[i].godina_rodjenja/GODINA_U_VEKU == v-1)
    {
        i--;
    }
    i++;
    // ispis
    while (naucnici[i].godina_rodjenja/GODINA_U_VEKU == v-1)
    {
        printf("%s %s\n", naucnici[i].ime, naucnici[i].prezime);
        i++;
    }

    fclose(dat);
    free(naucnici);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

Naucnik *ucitaj_niz_naucnika(FILE *f, int *n)
{
    Naucnik *niz = malloc(KORAK * sizeof(Naucnik));
    if (NULL == niz)
    {
        greska();
    }
    
    int i = 0;
    while (fscanf(f, "%s%s%d", niz[i].ime, niz[i].prezime, &niz[i].godina_rodjenja) != EOF)
    {
        i++;
        if (i % KORAK == 0)
        {
            niz = realloc(niz, (i + KORAK)*sizeof(Naucnik));
            if (NULL == niz)
            {
                greska();
            }
        }
    }
    
    *n = i;
    return niz;
}

int uporedi(const void *kljuc, const void *element)
{
    int k = *(int *)kljuc;
    Naucnik *e = (Naucnik *)element;

    if (k-1 < e->godina_rodjenja/GODINA_U_VEKU)
    {
        return -1;
    }
    else if (k-1 > e->godina_rodjenja/GODINA_U_VEKU)
    {
        return 1;
    }
    
    return 0;
}