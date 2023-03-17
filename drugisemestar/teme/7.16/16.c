#include <stdio.h>
#include <stdlib.h>

void greska();
int f16(int* a, int n);

int main()
{
    int n;
    int* niz;
    scanf("%d", &n);
    if(n <= 0)
        greska();
    
    niz = (int*)malloc(n * sizeof(int));
    if(NULL == niz)
        greska();
    
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    int rez = f16(niz, n);
    if(rez == 0)
        puts("-");
    else
        printf("%d\n", rez);

    free(niz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int f16(int* a, int n)
{
    if(n == 0)
        return 0;
    
    int proizvod_neparnih = f16(a, n-1);
    if(a[n-1] % 2) {
        if(proizvod_neparnih == 0)
            proizvod_neparnih = 1;
        proizvod_neparnih *= a[n-1];
    }
    
    return proizvod_neparnih;
}