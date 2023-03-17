#include <stdio.h>
#define MAX_IME 31
#define MAX 100

typedef struct{
    char ime[MAX_IME];
    double poeni;
} TAKMICAR;

void prva_tri_mesta(TAKMICAR takmicari[], int n) {
    int i, max, max_index, prva_tri=3;
    while(prva_tri) {
        max=takmicari[0].poeni;
        max_index=0;
        for(i=1; i<n; i++) {
            if(max<takmicari[i].poeni) {
                max=takmicari[i].poeni;
                max_index=i;
            }
        }
        printf("%s ", takmicari[max_index].ime);
        max=0; 
        takmicari[max_index].poeni=0;
        prva_tri--;
    }
    printf("\n");
}

int main() {
    int n;
    TAKMICAR takmicari[MAX];
    scanf("%d", &n);
    if(n<3 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    int i;
    for(i=0; i<n; i++) {
        scanf("%s %lf", takmicari[i].ime, &takmicari[i].poeni);
        if(takmicari[i].poeni<0 || takmicari[i].poeni>100) {
            printf("-1\n");
            return 1;
        }
    }
    prva_tri_mesta(takmicari, n);
}
