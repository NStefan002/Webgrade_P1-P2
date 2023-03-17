#include <stdio.h>
#include <stdlib.h>

void greska();
void f12(int *a, int n);
void alociraj_i_ucitaj(int** a, int n);
void ispisi(int* a, int n);

int main()
{
    int* a, n;
    scanf("%d", &n);

    alociraj_i_ucitaj(&a, n);
    f12(a, n);
    ispisi(a, n);

    free(a);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void f12(int *a, int n)
{
    if(n <= 2)
        return;
    
    int an1, an2, an3;
    an1 = a[n-1];
    an2 = a[n-2];
    an3 = a[n-3];

    f12(a, n-1);
    
    if(an2 == an1 + an3) 
        a[n-2] = 0;
}

void alociraj_i_ucitaj(int** a, int n)
{
    int* p = *a;
    p = (int*)malloc(n * sizeof(int));
    if(NULL == p)
        greska();
    
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);
    
    *a = p;
}

void ispisi(int* a, int n)
{
    if(n == 0) {
        putchar('\n');
        return;
    }
    
    printf("%d ", *a);
    ispisi(a+1, n-1);
}