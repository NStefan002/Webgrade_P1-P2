#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_REC 256

void greska();
int uslov(char s[]);

int main() {
    FILE* ulazna, *izlazna;

    ulazna = fopen("razno.txt", "r");
    if(NULL == ulazna)
        greska();

    izlazna = fopen("palindromi.txt", "w");
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
    int i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if(tolower(s[i]) != tolower(s[j]))
            return 0;
    }
    return 1;
}