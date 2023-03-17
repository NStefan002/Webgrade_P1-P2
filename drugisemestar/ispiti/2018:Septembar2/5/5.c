#include "stabla.h"

int br_neparnih_listova(Cvor* koren);

int main()
{
    FILE* f = fopen("stablo.txt", "r");
    if (NULL == f)
    {
        greska();
    }
    
    Cvor* stablo = NULL;
    ucitaj_stablo(&stablo, f);

    printf("%d\n", br_neparnih_listova(stablo));

    oslobodi_stablo(stablo);
    return 0;
}

int br_neparnih_listova(Cvor* koren)
{
    if (NULL == koren)      // ako je stablo prazno
    {
        return 0;
    }
    
    if (NULL == koren->levo && NULL == koren->desno && koren->vrednost % 2)
    {
        return 1;
    }
    
    int br_levo = br_neparnih_listova(koren->levo);
    int br_desno = br_neparnih_listova(koren->desno);

    return br_levo + br_desno;
}