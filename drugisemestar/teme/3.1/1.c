#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int im;
    int br;
}RAZLOMAK;

void greska();
void X(FILE* izlaz, RAZLOMAK* niz, int n);
void Y(FILE* izlaz, RAZLOMAK* niz, int n);
void X_Y(FILE* izlaz, RAZLOMAK* niz, int n);

int main(int argc, char* argv[]) {
    if(argc != 4)
        greska("Broj argumenata");
    
    if(argv[3][0] != '-' || (argv[3][1] != 'x' && argv[3][1] != 'y'))
        greska();
    
    FILE* ulaz, *izlaz;
    
    ulaz = fopen(argv[1], "r");
    if(NULL == ulaz)
        greska();
    
    izlaz = fopen(argv[2], "w");
    if(NULL == izlaz)
        greska();
    
    int n;
    fscanf(ulaz, "%d", &n);
    RAZLOMAK* razlomci;
    
    razlomci = (RAZLOMAK*)malloc(n * sizeof(RAZLOMAK));
    if(NULL == razlomci)
        greska();
    
    int i;
    for(i = 0; i < n; i++) {
        fscanf(ulaz, "%d/%d", &razlomci[i].br, &razlomci[i].im);
        if(razlomci[i].br == 0 || razlomci[i].im == 0)
            greska();
    }
    
    if(argv[3][1] == 'x') {
        if(argv[3][2]) {
            if(argv[3][2] != 'y')
                greska();
            else
                X_Y(izlaz, razlomci, n);
        }
        else
            X(izlaz, razlomci, n);
    }
    else if(argv[3][1] == 'y') {
        if(argv[3][2]) {
            if(argv[3][2] != 'x')
                greska();
            else
                X_Y(izlaz, razlomci, n);
        }
        else
            Y(izlaz, razlomci, n);
    }        
    else   
        greska();


    fclose(ulaz);
    fclose(izlaz);
    free(razlomci);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void X(FILE* izlaz, RAZLOMAK* niz, int n) {
    int znak, i;
    for(i = 0; i < n; i++) {
        znak = (niz[i].br * niz[i].im) / abs(niz[i].br * niz[i].im);
        fprintf(izlaz, "%d/%d\n", znak * abs(niz[i].im), abs(niz[i].br));
    }   
}

void Y(FILE* izlaz, RAZLOMAK* niz, int n) {
    int i;
    for(i = 0; i < n; i++) 
        fprintf(izlaz, "%g\n", (float) niz[i].im / niz[i].br); 
}

void X_Y(FILE* izlaz, RAZLOMAK* niz, int n) {
    int i, znak;
    for(i = 0; i < n; i++) {
        znak = (niz[i].br * niz[i].im) / abs(niz[i].br * niz[i].im);
        fprintf(izlaz, "%d/%d %g\n", znak * abs(niz[i].im), abs(niz[i].br), (float) niz[i].im / niz[i].br);
    }
}