#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_DUZINA_NISKE (255+1) /* 255 karaktera i jos 1 za terminalnu nulu */

int pogodjena_tajna_rec(char tajnaRec[], char pokusaji[])
{
    /***POCETAK KODA***/
    int i, j, p;
    int k = strlen(tajnaRec);
    for(i = 0; i < pokusaji[i]; i++) {
        p = 0;
        for(j = 0; tajnaRec[j]; j++) {
            if(pokusaji[i] == tajnaRec[j]) {
                p = 1;
                k--;
            }
        }
        if(p == 0)
            return 0;   
    }
    if(k > 0)
        return 0;

    return 1;
    /***KRAJ KODA***/
}

int main()
{
    char tajnaRec[MAKS_DUZINA_NISKE], pokusaji[MAKS_DUZINA_NISKE];
    char formatNiska[32];
    sprintf(formatNiska, "%%%ds%%%ds", MAKS_DUZINA_NISKE-1, MAKS_DUZINA_NISKE-1);
    scanf(formatNiska, tajnaRec, pokusaji);
    printf("%d\n", pogodjena_tajna_rec(tajnaRec, pokusaji));
    return 0;
}
