#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_REC 256

void greska();
int uslov(char s[]);

int main() {
    FILE* ulazna, *izlazna;

    ulazna = fopen("ulaz.txt", "r");
    if(NULL == ulazna)
        greska();

    izlazna = fopen("izlaz.txt", "w");
    if(NULL == izlazna)
        greska();
    
    char rec[MAX_REC];
    while(fscanf(ulazna, "%s", rec) != EOF) 
        if(uslov(rec))
            fprintf(izlazna, "%s ", rec);

    fclose(ulazna);
    fclose(izlazna);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int uslov(char s[]) {
    int i, zbir_ASCII = 0;
    for(i = 0; s[i]; i++) 
        zbir_ASCII += s[i];

    if(zbir_ASCII > 1000)
        return 1;
    else
        return 0;
}