#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void anuliraj(Cvor *lista);
int zbir_elemenata_liste(Cvor *lista);

int main()
{
    Cvor *lista = NULL;
    ucitaj_listu(&lista, stdin);

    anuliraj(lista);
    ispisi_listu(lista);
    
    oslobodi_listu(lista);
    return 0;
}

int zbir_elemenata_liste(Cvor *lista)
{
    int zbir = 0;
    for (; lista != NULL; lista = lista->sledeci)
    {
        zbir += lista->vrednost;
    }
    
    return zbir;
}

void anuliraj(Cvor *lista)
{
    if (NULL == lista)
    {
        return;
    }
    
    int zbir_prethodnih = 0;
    int zbir_narednih = zbir_elemenata_liste(lista);

    for (; lista != NULL; lista = lista->sledeci)
    {
        int tmp = lista->vrednost;
        zbir_narednih -= tmp;
        if (zbir_prethodnih > zbir_narednih)
        {
            lista->vrednost = 0;
        }
        
        zbir_prethodnih += tmp;
    }
}