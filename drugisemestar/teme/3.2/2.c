#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_REC 31
#define MAX_DAT 21

typedef struct{
    char marka[MAX_REC];
    char model[MAX_REC];
    int cena;
}AUTO;

typedef struct{
    char marka[MAX_REC];
    int br;
    float prosek;
}PROSEK;

void greska();
int postoji(char* marka, AUTO* niz, int dimenzija);
int postoji_ucitan(char* marka, PROSEK* niz, int dimenzija);

int main(int argc, char** argv) {
    // provera broja argumenata
    if(argc != 2)
        greska();
    
    // ucitavanje imena datoteke i otvaranje datoteke
    char ime_dat[MAX_DAT];
    scanf("%s", ime_dat);
    FILE* dat = fopen(ime_dat, "r");
    if(NULL == dat)
        greska();

    // ucitavanje podataka iz datoteke
    int br_automobila;
    fscanf(dat, "%d", &br_automobila);
    
    AUTO* automobili;
    automobili = (AUTO*)malloc(br_automobila * sizeof(AUTO));
    if(NULL == automobili)
        greska();
    
    int i, j, p, br_marki = 0;
    for(i = 0; i < br_automobila; i++) {
        fscanf(dat, "%s%s%d", automobili[i].marka, automobili[i].model, &automobili[i].cena);
        p = 1;
        for(j = 0; j < i; j++) {
            if(strcmp(automobili[i].marka, automobili[j].marka) == 0)
                p = 0;
        }
        if(p)
            br_marki++;
    }

    PROSEK* ppm; // prosek po marki
    ppm = (PROSEK*)malloc(br_marki * sizeof(PROSEK));
    if(NULL == ppm)
        greska();
    
    // formiranje niza za prosek po marki
    int q;
    for(i = 0, p = 0; i < br_marki; i++) {
        ppm[i].br = 0;
        ppm[i].prosek = 0;
        strcpy(ppm[i].marka, automobili[p].marka);
        q = (i > p)? i : p;
        while(postoji(ppm[i].marka, automobili, q) || postoji_ucitan(ppm[i].marka, ppm, i)) {
            p++;
            strcpy(ppm[i].marka, automobili[p].marka);
        }
        for(j = 0; j < br_automobila; j++) {
            if(strcmp(ppm[i].marka, automobili[j].marka) == 0) {
                ppm[i].br++;
                ppm[i].prosek += automobili[j].cena;
            }
        }
        ppm[i].prosek /= (float)ppm[i].br;
    }

    // pretraga po budzetu
    int budzet = atoi(argv[1]);
    p = 0;
    for(i = 0; i < br_automobila; i++) {
        if(automobili[i].cena <= budzet) {
            for(j = 0; j < br_marki; j++) {
                if(strcmp(automobili[i].marka, ppm[j].marka) == 0) {
                    p = 1;
                    printf("%s %s %d ", automobili[i].marka, automobili[i].model, automobili[i].cena);
                    printf("[Prosek za %s: %g]\n", ppm[j].marka, ppm[j].prosek);
                }
            }
        }
    }
    if(!p)
        printf("-\n");

    // zatvaranje datoteke i oslobadjanje memorije
    fclose(dat);
    free(automobili);
    free(ppm);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int postoji(char* marka, AUTO* niz, int dimenzija) {
    int i;
    for(i = 0; i < dimenzija; i++) {
        if(strcmp(marka, niz[i].marka) == 0)
            return 1;
    }
    return 0;
}

int postoji_ucitan(char* marka, PROSEK* niz, int dimenzija) {
    int i;
    for(i = 0; i < dimenzija; i++) {
        if(strcmp(marka, niz[i].marka) == 0)
            return 1;
    }
    return 0;
}