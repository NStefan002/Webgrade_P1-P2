#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cvor *dodaj_nule(Cvor *lista, int k, int p);

int main()
{
    int k, p;
    scanf("%d%d", &k, &p);
    if (p >= k)
    {
        greska();
    }
    
    Cvor *lista = NULL;
    ucitaj_listu(&lista, stdin);

    Cvor *rez_lista = dodaj_nule(lista, k, p);
    ispisi_listu(rez_lista);

    oslobodi_listu(rez_lista);
    return 0;
}

Cvor *dodaj_nule(Cvor *lista, int k, int p)
{
    if (lista == NULL || lista->sledeci == NULL)
    {
        return lista;
    }
    
    Cvor *tekuci = lista;

    while (tekuci->sledeci != NULL)
    {
        Cvor *naredni = tekuci->sledeci;
        int suma_susednih = tekuci->vrednost + naredni->vrednost;
        if (suma_susednih % k == p || k + (suma_susednih % k) == p)
        {
            Cvor *prva_nula = napravi_cvor(0);
            Cvor *druga_nula = napravi_cvor(0);
            
            prva_nula->sledeci = druga_nula;
            druga_nula->sledeci = tekuci->sledeci;
            tekuci->sledeci = prva_nula;
        }
        
        tekuci = naredni;
    }

    return lista;
}