#include <stdio.h>
#define MAX_IME 21
#define MAX 100 

typedef struct{
    char ime[MAX_IME];
    char prezime[MAX_IME];
    double prosek;
    int godina;
}Student;

void ucitaj_i_prebroj(Student studenti[], int n) {
    int i, r=0;
    for(i=0; i<n; i++) {
        scanf("%s %s %lf %d", studenti[i].ime, studenti[i].prezime, &studenti[i].prosek, &studenti[i].godina);
        if(studenti[i].prosek>9 && studenti[i].godina==4) r++;
    }
    printf("%d\n", r);
}

int main() {
    int n;
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    Student studenti[MAX];
    ucitaj_i_prebroj(studenti, n);
}
