#include <stdio.h>
#include <string.h>
#define MAX_IME 21
#define MAX 100

typedef struct{
    char naziv[MAX_IME];
    char zanr[MAX_IME];
    double ocena;
} Film;

int main() {
    int n;
    Film filmovi[MAX];
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    int i;
    for(i=0; i<n; i++) {
        scanf("%s %s %lf", filmovi[i].naziv, filmovi[i].zanr, &filmovi[i].ocena);
    }
    char zeljeni_zanr[MAX_IME];
    scanf(" %s", zeljeni_zanr);
    int indeksi[MAX]={};
    for(i=0; i<n; i++)
        if(strcmp(zeljeni_zanr,filmovi[i].zanr)==0)
            indeksi[i]++;
    
    double max=0;
    int max_indeks;
    for(i=0; i<n; i++) 
        if(indeksi[i])
            if(max<filmovi[i].ocena) {
                max=filmovi[i].ocena;
                max_indeks=i;
            }
    
    if(max)
        printf("%s\n", filmovi[max_indeks].naziv);
    else
        printf("-1\n");
}
