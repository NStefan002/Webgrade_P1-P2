#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greska();
int unesiSkup(char** s, FILE* f);
void prebroj(char* s, int* br_slova, int* br_cifara);

int main(int argc, char** argv) {
    // provera broja argumenata
    if(argc != 2)
        greska();
    
    // otvaranje datoteke
    FILE* dat;
    dat = fopen(argv[1], "r");
    if(NULL == dat)
        greska();
    
    // pozivi funkcija
    char* niz;
    int br_c, br_s;
    br_c = unesiSkup(&niz, dat);
    prebroj(niz, &br_s, &br_c);

    printf("broj slova: %d\nbroj cifara: %d\n", br_s, br_c);

    // zatvaranje datoteke i oslobadjanje memorije
    fclose(dat);
    free(niz);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int unesiSkup(char** s, FILE* f) {
    int br_elemenata = 0;
    char c; // radi ucitavanja
    while((c = fgetc(f)) != EOF) {
        if(!isdigit(c) && !isalpha(c))
            break;
        br_elemenata++;
    }

    // alokacija memorije za skup karaktera
    *s = (char*)malloc(br_elemenata * sizeof(char));
    if(NULL == *s)
        greska();
    
    // vracanje kursora na pocetak fajla
    fseek(f, 0, SEEK_SET);
    if(NULL == f)
        greska();

    // ucitavanje niza
    fgets(*s, br_elemenata+1, f);

    return br_elemenata;
}

void prebroj(char* s, int* br_slova, int* br_cifara) {
    int n = *br_cifara;
    *br_cifara = *br_slova = 0;
    int i;
    for(i = 0; i < n; i++) {
        if(isdigit(s[i]))
            (*br_cifara)++;
        else
            (*br_slova)++;
    }
}
