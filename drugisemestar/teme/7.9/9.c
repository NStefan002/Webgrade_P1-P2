#include <stdio.h>
#include <stdlib.h>

#define KORAK 10 // za realokaciju memorije
#define MAX 21

// definisanje strukture za rad sa podacima o korisnicima
typedef struct{
    char identifikacija[MAX];
    int iznos;
}SALDO;

void greska();
void pretraga(SALDO* a, int n, float uslov);

int main()
{   
    // otvaranje datoteke
    FILE* f = fopen("saldo.txt", "r");
    if(NULL == f)
        greska();
    
    // formiranje niza sa informacijama o korisnicima
    SALDO* niz;
    int alocirano = KORAK;
    float prosek = 0; int br_korisnika_sa_neg_saldom = 0;
    niz = (SALDO*)malloc(alocirano * sizeof(SALDO));
    if(NULL == niz)
        greska();

    int i = 0;
    while(fscanf(f, "%s%d", niz[i].identifikacija, &niz[i].iznos) == 2) {
        if(niz[i].iznos < 0) {
            prosek += niz[i].iznos;
            br_korisnika_sa_neg_saldom++;
        }
        
        i++;
        // realokacija memorije po potrebi
        if(i == alocirano) {
            alocirano += KORAK;
            niz = (SALDO*)realloc(niz, alocirano * sizeof(SALDO));
            if(NULL == niz)
                greska();
        }
    }

    alocirano = i;
    prosek /= br_korisnika_sa_neg_saldom;

    pretraga(niz, alocirano, prosek);

    // zatvaranje datoteke, oslobadjanje memorije i izlazak iz programa
    fclose(f);
    free(niz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void pretraga(SALDO* a, int n, float uslov)
{
    int i;
    for(i = 0; i < n; i++) {
        if(a[i].iznos < uslov)
            printf("%s\n", a[i].identifikacija);
    }
}