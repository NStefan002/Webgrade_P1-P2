#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int dan;
    int mesec;
    int godina;
} Datum;

Datum sledeci_dan(Datum d)
{
    /***POCETAK KODA***/

    /***KRAJ KODA***/
}

int main()
{
    Datum d;
    scanf("%d%d%d", &d.dan, &d.mesec, &d.godina);
    Datum rezultat = sledeci_dan(d);
    printf("%d.%d.%d.\n", rezultat.dan, rezultat.mesec, rezultat.godina);
    return 0;
}
