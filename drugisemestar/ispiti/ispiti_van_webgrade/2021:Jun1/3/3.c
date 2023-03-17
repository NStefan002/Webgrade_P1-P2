#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

typedef struct _tacka
{
    float x;
    float y;
    char ime[MAX+1];
} Tacka;

void greska();
int ispravno_ime(const char *p);
void ucitaj_tacke(Tacka *niz, int n, FILE *f);
void ispisi(Tacka *niz, int n);
int uporedi(const void *a, const void *b);

int main()
{
    FILE *f = fopen("tacke.txt", "r");
    if (NULL == f)
    {
        greska();
    }

    int br_tacaka;
    fscanf(f, "%d", &br_tacaka);
    if (br_tacaka <= 0)
    {
        greska();
    }
    
    Tacka *niz_tacaka = malloc(br_tacaka * sizeof(Tacka));
    if (NULL == niz_tacaka)
    {
        greska();
    }

    ucitaj_tacke(niz_tacaka, br_tacaka, f);
    
    qsort(niz_tacaka, br_tacaka, sizeof(Tacka), &uporedi);
    ispisi(niz_tacaka, br_tacaka);

    fclose(f);
    free(niz_tacaka);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int ispravno_ime(const char *p)
{
    for (int i = 0; p[i]; i++)
    {
        if (!isalpha(p[i]) || isupper(p[i]))
        {
            return 0;
        }
    }
    
    return 1;
}

void ucitaj_tacke(Tacka *niz, int n, FILE *f)
{
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%f%f%s", &niz[i].x, &niz[i].y, niz[i].ime);
        if (!ispravno_ime(niz[i].ime))
        {
            free(niz);
            greska(); 
        }
    }
}

void ispisi(Tacka *niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%g %g %s\n", niz[i].x, niz[i].y, niz[i].ime);
    }
}

int uporedi(const void *a, const void *b)
{
    Tacka *x = (Tacka *)a;
    Tacka *y = (Tacka *)b;

    if (x->x < y->x)
    {
        return -1;
    }
    else if (x->x > y->x)
    {
        return 1;
    }
    
    if (x->y > y->y)
    {
        return -1;
    }
    else if (x->y < y->y)
    {
        return 1;
    }
    
    return strcmp(x->ime, y->ime);
}