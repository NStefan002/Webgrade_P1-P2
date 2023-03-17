#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KORAK 10  // za realokaciju memorije
#define MAX 51
#define MAX_BAR_KOD 21

// definisanje strukture za rad sa podacima o artiklima
typedef struct{
    char bar_kod[MAX_BAR_KOD];
    char ime_artikla[MAX];
    char proizvodjac[MAX];
    float cena;
}ARTIKAL;


void greska();
int uporedi(const void* s1, const void* s2);

int main()
{
    char ime_dat[MAX];
    scanf("%s", ime_dat);
    // otvaranje datoteke u kojoj se nalaze podaci o artiklima
    FILE* ulaz = fopen(ime_dat, "r");
    if(NULL == ulaz)
        greska();

    // alokacija memorije za niz artikala
    int alocirano = KORAK;
    ARTIKAL* niz = (ARTIKAL*)malloc(alocirano * sizeof(ARTIKAL));
    if(NULL == niz)
        greska();

    // ucitavanje niza
    int i = 0;
    while(fscanf(ulaz, "%s%s%s%f", niz[i].bar_kod, niz[i].ime_artikla, niz[i].proizvodjac, &niz[i].cena) == 4) {
        i++;
        // realokacija po potrebi
        if(i == alocirano) {
            alocirano += KORAK;
            niz = (ARTIKAL*)realloc(niz, alocirano * sizeof(ARTIKAL));
            if(NULL == niz)
                greska();
        }
    }

    // pretraga po bar kodovima
    char kljuc[MAX_BAR_KOD];
    scanf("%s", kljuc);
    int (*fp)(const void*, const void*) = &uporedi; // radi probe
    float zbir = 0;
    ARTIKAL* pronadjen_clan;

    while(strcmp(kljuc, "0")) {
        pronadjen_clan = (ARTIKAL*)bsearch(kljuc, niz, i, sizeof(ARTIKAL), fp);
        if(NULL == pronadjen_clan)
            printf("Nepostojeci bar kod\n");
        else
            zbir += pronadjen_clan->cena;

        scanf("%s", kljuc);
    }

    printf("%g\n", zbir);

    // oslobadjanje memorije, zatvaranje datoteke i izlazak iz programa
    free(niz);
    fclose(ulaz);    
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int uporedi(const void* s1, const void* s2)
{
    ARTIKAL* p1 = (ARTIKAL*)s1;
    char* p2 = (char*)s2;

    return strcmp(p1->bar_kod, p2); 
}