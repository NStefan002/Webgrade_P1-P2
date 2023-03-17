#include <stdio.h>
#include <stdlib.h>

void greska();
int binarna_pretraga_k_tocifrenog_broja(int* a, int n, int k);
int broj_cifara(int x);
int* alociraj_i_ucitaj(int n);

int main()
{
    int* a, k, n;
    scanf("%d%d", &k, &n);
    if(k <= 0 || n <= 0)
        greska();

    a = alociraj_i_ucitaj(n);
    
    int i = binarna_pretraga_k_tocifrenog_broja(a, n, k);
    if(i != -1)
        printf("%d\n", i);

    free(a);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int binarna_pretraga_k_tocifrenog_broja(int* a, int n, int k)
{
    int l = 0, d = n - 1;   // levi deo, desni deo
    int s;                  // srednji clan
    int br_cif;

    while(l <= d) {
        s = l + (d - l)/2;
        br_cif = broj_cifara(abs(a[s]));
        if(br_cif == k) {
            if(br_cif == broj_cifara(a[s-1]) && s >= 1) 
                d = s-1;
            else
                return s;
        }
        else if(br_cif < k) 
            l = s + 1;
        else 
            d = s - 1;
    }

    return -1;
}

int broj_cifara(int x)
{
    if(x <= 9)
        return 1;
    
    int br_cifara = broj_cifara(x/10);

    return br_cifara + 1;
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