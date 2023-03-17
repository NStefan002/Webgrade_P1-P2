#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_REC 128
#define MAX_IME 64

void greska();
void rotiraj(char s[]);

int main() {
    char ime[MAX_IME];
    int k;
    scanf("%s%d", ime, &k);
    if(k < 0)
        greska();
    
    FILE* ulazna, *izlazna;
    
    ulazna = fopen(ime, "r");
    if(NULL == ulazna)
        greska();
    
    izlazna = fopen("rotirano.txt", "w");
    if(NULL == izlazna)
        greska();
    
    int i;
    char rec[MAX_REC];
    while(fscanf(ulazna, "%s", rec) != EOF) {
        for(i = 0; i < k; i++)
        rotiraj(rec);
        fprintf(izlazna, "%s ", rec);
    }


    fclose(ulazna);
    fclose(izlazna);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void rotiraj(char s[]) {
    int i;
    char p = s[0];
    for(i = 0; s[i]; i++) {
        if(i == strlen(s) - 1)
            s[i] = p;
        else
            s[i] = s[i+1];
    }
}