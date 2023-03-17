#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 65
#define SAT 6 // 4 cifre, dve tacke i term. nula

#define KORAK 10 // za realokaciju memorije

// definisanje strukture za cuvanje podataka o filmovima
typedef struct
{
    char ime[MAX];
    char vreme[SAT];
}Film;

void greska();
Film* ucitaj(int* n);
void ispisi(Film* niz, int n);
int uporedi(const void* a, const void* b);
char* najvise_projekcija(Film* niz, int n);

int main()
{
    int n;
    Film* niz = ucitaj(&n);

    qsort(niz, n, sizeof(Film), &uporedi);

    ispisi(niz, n);

    char* max_sat = najvise_projekcija(niz, n);
    printf("%s\n", max_sat);

    free(niz);
    free(max_sat);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

Film* ucitaj(int* n)
{
    FILE* f = fopen("bioskop.txt", "r");
    if (NULL == f)
    {
        greska();
    }

    int alocirano = KORAK;
    Film* niz = malloc(alocirano * sizeof(Film));
    if (NULL == niz)
    {
        greska();
    }
    int i = 0;
    while (fscanf(f, "%s%s", niz[i].ime, niz[i].vreme) == 2)
    {
        i++;
        if (alocirano == i)
        {
            alocirano += KORAK;
            niz = realloc(niz, alocirano * sizeof(Film));
            if (NULL == niz)
            {
                greska();
            }
        }
    }
    
    *n = i;
    return niz;
}

void ispisi(Film* niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", niz[i].ime);
    }
}

int uporedi(const void* a, const void* b)
{
    char* x = ((Film*)a)->vreme;
    char* y = ((Film*)b)->vreme;

    if (strcmp(x, y) > 0)
    {
        return 1;
    }
    else if (strcmp(x, y) < 0)
    {
        return -1;
    }
    return 0;
}

char* najvise_projekcija(Film* niz, int n)
{
    int ponavljanja = 1;
    int max = 0;

    int sat1, sat2;
    char* max_sat = malloc(SAT * sizeof(char));
    if (NULL == max_sat)
    {
        greska();
    }
    
    int i;
    sscanf(niz[0].vreme, "%d:%*d", &sat1);
    for (i = 1; i < n; i++)
    {
        sscanf(niz[i].vreme, "%d:%*d", &sat2);

        if (sat1 == sat2)
        {
            ponavljanja++;
        }
        else
        {
            if (max < ponavljanja)
            {
                max = ponavljanja;
                strncpy(max_sat, niz[i-1].vreme, 2);  // 2 za sate samo
                max_sat[2] = '\0';
                strcat(max_sat, ":00");
            }
            ponavljanja = 1;
        }

        sat1 = sat2;
    }
    
    if (max < ponavljanja)
    {
        max = ponavljanja;
        strncpy(max_sat, niz[i-1].vreme, 2);  
        max_sat[2] = '\0';
        strcat(max_sat, ":00");
    }

    max_sat[SAT-1] = '\0';

    return max_sat;
}