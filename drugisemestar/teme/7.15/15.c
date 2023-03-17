#include <stdio.h>
#include <stdlib.h>

void greska();
int* alociraj_i_ucitaj(int n);
int najblizi(int* a, int i, int n, int x);
int pretraga_najblizeg(int* a, int n, int x);

int main()
{
    int x, n;
    int* niz;
    scanf("%d%d", &x, &n);
    if(n <= 0)
        greska();

    niz = alociraj_i_ucitaj(n);    

    printf("%d\n", pretraga_najblizeg(niz, n, x));

    free(niz);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int* alociraj_i_ucitaj(int n)
{
    int* p = (int*)malloc(n * sizeof(int));
    if(NULL == p)
        greska();
    
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);
    
    return p;
}

int najblizi(int* a, int i, int n, int x)
{
    int razlika = abs(a[i] - x);
    
    if(i > 0 && i < n - 1) 
        if(razlika < abs(a[i-1] - x) && razlika <= abs(a[i+1] - x))
            return 1;

    if(i == 0 && n >= 2)
        if(razlika <= abs(a[1] - x))
            return 1;
    
    if(i == n - 1 && n >= 2)
        if(razlika < abs(a[n-2] - x))
            return 1;
    
    if(n == 1)
        return 1;
    
    return 0;   // ako nista od prethodnih nije ispunjeno znaci nije najblizi
}

int pretraga_najblizeg(int* a, int n, int x)
{
    int l = 0, d = n - 1;   // levi deo, desni deo
    int s;                  // srednji clan

    while(l <= d) {
        s = l + (d - l)/2;
        if(najblizi(a, s, n, x))
            return a[s];
        
        if(a[s] < x)
            l = s + 1;
        else
            d = s - 1;
    }

    return -1;  // u slucaju neke greske
}