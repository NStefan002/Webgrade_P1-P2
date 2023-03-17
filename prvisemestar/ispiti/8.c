#include <stdio.h>
#define MAX_IME 21
#define MAX 100

typedef struct{
    char naziv[MAX_IME];
    double kolicina;
    double cena;
}Sastojak;

int main() {
    int n;
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    Sastojak torta[MAX];
    int i;
    double racun=0;
    for(i=0; i<n; i++) {
        scanf("%s %lf %lf", torta[i].naziv, &torta[i].kolicina, &torta[i].cena);
        if(torta[i].kolicina<0 || torta[i].cena<0) {
            printf("-1\n");
            return 1;
        }
        racun+=(torta[i].kolicina/100) * torta[i].cena; 
    }
    printf("%.2lf\n", racun);
}
