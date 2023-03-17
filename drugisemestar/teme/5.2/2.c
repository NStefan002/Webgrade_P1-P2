#include <stdio.h>
#include <stdlib.h>

void greska();
int maksimum_niza(int* a, int n);

int main()
{
    // ucitavanje dimenzije niza i provera njene ispravnosti
    int n;
    scanf("%d", &n);
    if(n < 0)
        greska();
    
    // ukoliko je n = 0, program se zavrsava, ali nije greska
    if(n == 0)
        exit(EXIT_SUCCESS);

    // alociranje memorije za niz i ucitavanje niza
    int* niz = (int*)malloc(n * sizeof(int));
    if(NULL == niz)
        greska();
    
    for(int i = 0; i < n; i++)
        scanf("%d", niz + i);

    // ispis maksimuma ucitanog niza
    printf("%d\n", maksimum_niza(niz, n));

    // oslobadjanje alocirane memorije
    free(niz);
    niz = NULL;
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int maksimum_niza(int* a, int n)
{
    if(n == 1)
        return a[0];
    
    int max = maksimum_niza(a+1, n-1);
    if(max < a[0])
        max = a[0];
    
    return max;
}