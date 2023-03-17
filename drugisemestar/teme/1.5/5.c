#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greska();

int main() {
    FILE* ulazna, *izlazna;
    
    ulazna = fopen("plain.txt", "r");
    if(NULL == ulazna)
        greska();
    
    izlazna = fopen("sifra.txt", "w");
    if(NULL == izlazna)
        greska();
    
    char c;
    while((c = fgetc(ulazna)) != EOF) {
        if(isupper(c))
            c = (c == 'A') ? 'z' : (tolower(c) - 1);
        else if(islower(c))
            c = (c == 'a') ? 'Z' : (toupper(c) - 1);
        
        fputc(c, izlazna);
    }


    fclose(ulazna);
    fclose(izlazna);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}