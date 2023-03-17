#include <stdio.h>
#include <stdlib.h>
#define MAX_IME 21

void greska();

int main() {
    char naziv1[MAX_IME], naziv2[MAX_IME];
    scanf("%s%s", naziv1, naziv2);
    
    FILE* ulazna, *izlazna;
    ulazna = fopen(naziv1, "r");
    if(NULL == ulazna)
        greska();

    izlazna = fopen(naziv2, "w");
    if(NULL == izlazna)
        greska();

    char c;
    while((c = fgetc(ulazna)) != EOF) {
        fputc(c, izlazna);
        fgetc(ulazna);
    }

    fclose(ulazna);
    fclose(izlazna); 
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}