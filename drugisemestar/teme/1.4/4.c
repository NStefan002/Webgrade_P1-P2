#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_IME 64

void greska();

int main() {
    char ime_ulazne[MAX_IME], ime_izlazne[MAX_IME];
    scanf("%s%s", ime_ulazne, ime_izlazne);

    FILE* ulazna, *izlazna;
    ulazna = fopen(ime_ulazne, "r");
    if(NULL == ulazna)
        greska();

    izlazna = fopen(ime_izlazne, "w");
    if(NULL == izlazna)
        greska();
    
    char c;
    while((c = fgetc(ulazna)) != EOF) {
        if(isdigit(c))
            fputc('0', izlazna);
        else if(isalpha(c))
            fputc('1', izlazna);
        else 
            fputc('2', izlazna);
    }

    fclose(ulazna);
    fclose(izlazna);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}