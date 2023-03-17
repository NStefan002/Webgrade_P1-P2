#include<stdio.h>
#define MAX_IME 21
#define MAX 100

typedef struct{
    char ime[MAX_IME];
    char prezime[MAX_IME];
    double visina;
    double masa;
}BMI;

int main() {
    int n;
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    int i;
    BMI narod[MAX];
    for(i=0;i<n;i++){
        scanf("%s %s %lf %lf", narod[i].ime,
        narod[i].prezime, &narod[i].visina,
        &narod[i].masa);
    }
    int kategorija;
    scanf("%d",&kategorija);
    if(kategorija<=0 || kategorija>=5) {
        printf("-1\n");
        return 1;
    }
    for(i=0;i<n;i++){
        switch(kategorija){
            case(1):
                if(narod[i].masa/(narod[i].visina*narod[i].visina)<18.5)
                printf("%s %s\n", narod[i].ime, narod[i].prezime);
                break;
            case(2):
                if(narod[i].masa/(narod[i].visina*narod[i].visina)>=18.5 && narod[i].masa/(narod[i].visina*narod[i].visina)<25)
                printf("%s %s\n", narod[i].ime, narod[i].prezime);
                break;
            case(3):
                if(narod[i].masa/(narod[i].visina*narod[i].visina)>=25 && narod[i].masa/(narod[i].visina*narod[i].visina)<30)
                printf("%s %s\n", narod[i].ime, narod[i].prezime);
                break;
            case(4):
                if(narod[i].masa/(narod[i].visina*narod[i].visina)>=30)
                printf("%s %s\n", narod[i].ime, narod[i].prezime);
                break;
        }
    }
}
