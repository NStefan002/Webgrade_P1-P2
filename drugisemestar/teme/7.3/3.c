#include <stdio.h>
#include <stdlib.h>

#define KORAK 10

void greska();
int veci_od_proseka();

int main()
{
    printf("%d\n", veci_od_proseka());
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int veci_od_proseka()
{
    int broj_ucitanih = 0;
    float prosek = 0;
    int br_vecih_od_proseka = 0;

    int* niz, i = 0;
    int alocirano = KORAK;
    niz = (int*)malloc(alocirano * sizeof(int));
    if(NULL == niz)
        greska();
    
    scanf("%d", &niz[i]);

    while(niz[i] != 0) {
        broj_ucitanih++;
        prosek += (float)niz[i];

        i++;
        if(i == alocirano) {
            alocirano += KORAK;
            niz = (int*)realloc(niz, alocirano * sizeof(int));
            if(NULL == niz)
                greska();
        }
        scanf("%d", &niz[i]);
    }
    alocirano = i;

    prosek /= broj_ucitanih;

    for(i = 0; i < alocirano; i++) {
        if(niz[i] > prosek)
            br_vecih_od_proseka++;
    }

    free(niz);
    return br_vecih_od_proseka;
}