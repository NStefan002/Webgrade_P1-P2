#include <stdio.h>
#include <stdlib.h>

void greska();
void f11(int* a, int n, int x);
int* alociraj_i_ucitaj(int n);
void ispisi(int* a, int n);

int main()
{
    int* a, n, x;
    scanf("%d%d", &x, &n);

    a = alociraj_i_ucitaj(n);
    f11(a, n, x);
    ispisi(a, n);

    free(a);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void f11(int* a, int n, int x)
{// 1 2 3 
    if(n <= 1)
        return;
    
    int an1, an2;
    an1 = a[n-1];
    an2 = a[n-2];

    f11(a, n-1, x);
    if(an1 + an2 == x)
        a[n-1] = a[n-2] = 0;
}

int* alociraj_i_ucitaj(int n)
{
    int* p;
    p = (int*)malloc(n * sizeof(int));
    if(NULL == p)
        greska();
    
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);
    
    return p;
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