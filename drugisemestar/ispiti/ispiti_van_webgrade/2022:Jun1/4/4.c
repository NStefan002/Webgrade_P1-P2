#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

void ispisi_cvorove_sa_parnim_brojem_suseda(Cvor *koren, int jeste_koren);

int main()
{
    Cvor *stablo = NULL;
    ucitaj_stablo(&stablo, stdin);

    ispisi_cvorove_sa_parnim_brojem_suseda(stablo, 1);

    oslobodi_stablo(stablo);
    return 0;
}

void ispisi_cvorove_sa_parnim_brojem_suseda(Cvor *koren, int jeste_koren)
{
    if (koren == NULL)
    {
        return;
    }
    
    ispisi_cvorove_sa_parnim_brojem_suseda(koren->levo, 0);
    ispisi_cvorove_sa_parnim_brojem_suseda(koren->desno, 0);

    if (jeste_koren)
    {
        if ((koren->desno != NULL && koren->levo != NULL) || (koren->desno == NULL && koren->levo == NULL))
        {
            printf("%d ", koren->vrednost);
        }
        /* ako je u pitanju koren stabla potrebno je ili da ima oba deteta ili da nema nijedno 
        da bi imao paran broj suseda (2 ili 0) */
    }
    else
    {
        if ((koren->desno == NULL && koren->levo != NULL) || (koren->desno != NULL && koren->levo == NULL))
        {
            printf("%d ", koren->vrednost);
        }
        /* ako nije u pitanju koren stabla potrebno je da ima jedno dete da bi imao paran broj 
        suseda (jer vec ima jednog roditelja) */
    }
}