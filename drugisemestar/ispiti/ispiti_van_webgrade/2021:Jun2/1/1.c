#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct _mesto
{
    char naziv[MAX+1];
    int pbroj;
} Mesto;

void greska();
void ucitaj_mesta(Mesto *niz, int n, FILE *f);
int uporedi(const void *kljuc, const void *element);

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        greska();
    }
    
    FILE *f = fopen(argv[1], "r");
    if (NULL == f)
    {
        greska();
    }
    
    int broj_linija_datoteke = atoi(argv[2]);
    if (broj_linija_datoteke <= 0)
    {
        greska();
    }

    Mesto *mesta = malloc(broj_linija_datoteke * sizeof(Mesto));
    if (NULL == mesta)
    {
        greska();
    }
    
    ucitaj_mesta(mesta, broj_linija_datoteke, f);
    
    int kljuc;
    scanf("%d", &kljuc);
    if (kljuc <= 0)
    {
        free(mesta);
        greska();
    }
    
    Mesto *rez = bsearch(&kljuc, mesta, broj_linija_datoteke, sizeof(Mesto), &uporedi);
    if (rez != NULL)
    {
        printf("%s\n", rez->naziv);
    }

    free(mesta);
    fclose(f);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void ucitaj_mesta(Mesto *niz, int n, FILE *f)
{
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%s%d", niz[i].naziv, &niz[i].pbroj);
    }
}

int uporedi(const void *kljuc, const void *element)
{
    int *x = (int *)kljuc;
    int y = ((Mesto *)element)->pbroj;

    if (*x < y)
    {
        return -1;
    }
    else if (*x > y)
    {
        return 1;
    }
    
    return 0;
}