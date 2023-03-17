#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cvor* izbaci_fibonacijeve(Cvor* lista, int poz);
int jeste_fibonaci(int x);

int main()
{
    Cvor* lista = NULL;
    ucitaj_listu(&lista, stdin);

    Cvor* rez = izbaci_fibonacijeve(lista, 1);  
    ispisi_listu(rez);
    
    oslobodi_listu(rez);
    return 0;
}

int jeste_fibonaci(int x)
{
    int br1, br2;
    br1 = br2 = 1;
    while (br1 <= x)
    {
        if (x == br1 || x == br2)
        {
            return 1;
        }
        
        int tmp = br2;
        br2 += br1;
        br1 = tmp;   
    }
    return 0;
}

Cvor* izbaci_fibonacijeve(Cvor* lista, int poz)
{
    if (NULL == lista)
    {
        return NULL;
    }

    if (NULL == lista->sledeci)
    {
        if (jeste_fibonaci(poz))
        {
            free(lista);
            return NULL;
        }
        return lista;
    }
    

    Cvor* rez = lista;
    if (jeste_fibonaci(poz))
    {
        rez = lista->sledeci;
        free(lista);
        rez = izbaci_fibonacijeve(rez, poz+1);
    }
    else if (rez != NULL)
    {
        rez->sledeci = izbaci_fibonacijeve(rez->sledeci, poz+1);
    }
    
    return rez;
}   