#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_IME 64

void greska();

int main() {
    char ime_ulazne[MAX_IME], ime_izlazne[MAX_IME];
    int n;
    scanf("%s%s%d", ime_ulazne, ime_izlazne, &n);
    if(n <= 0)
        greska();

    FILE* ulaz, *izlaz;
    ulaz = fopen(ime_ulazne, "r");
    if(NULL == ulaz)
        greska();
    
    izlaz = fopen(ime_izlazne, "w");
    if(NULL == izlaz)
        greska();
    
    char rec[MAX_IME]; 
    fscanf(ulaz, "%s", rec);
    char c;
    int br_linije = 1, br_ponavljanja = 0;
    long unsigned int i;

    fgetc(ulaz);
    while((c = fgetc(ulaz)) != EOF) {
        while(c == rec[0]) {
            for(i = 1; i < strlen(rec); i++) {
                c = fgetc(ulaz);
                if(c != rec[i])
                    break;
            }
            if(i == strlen(rec)) 
                br_ponavljanja++;
            c = fgetc(ulaz);
        }

        if(c == '\n') {
            if(br_ponavljanja >= n)
                fprintf(izlaz, "%d:%d\n", br_ponavljanja, br_linije);
            br_linije++;
            br_ponavljanja = 0;
        }
    }
    if(br_ponavljanja >= n) 
        fprintf(izlaz, "%d:%d\n", br_ponavljanja, br_linije);

    fclose(ulaz);
    fclose(izlaz);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}