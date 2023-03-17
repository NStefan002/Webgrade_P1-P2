#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_DUZINA_NISKE (255+1) /* 255 karaktera i jos 1 za terminalnu nulu */

int jeste_rotacija(char s[], char srot[])
{
    /***POCETAK KODA***/
    if(strlen(s) != strlen(srot))
        return 0;
    
    int i = 0;

    while(s[i]) {
        if(s[i] == srot[0]) {
            if(strncmp(s+i, srot, strlen(s+i)) == 0 && strncmp(s, srot + strlen(srot) - i, strlen(srot + strlen(srot) - i)) == 0)
                return 1;
        }
        i++;
    }

    return 0;
    /***KRAJ KODA***/
}

int main()
{
    char s[MAKS_DUZINA_NISKE], srot[MAKS_DUZINA_NISKE];
    char formatNiska[32];
    sprintf(formatNiska, "%%%ds%%%ds", MAKS_DUZINA_NISKE-1, MAKS_DUZINA_NISKE-1);
    scanf(formatNiska, s, srot);
    printf("%d\n", jeste_rotacija(s, srot));
    return 0;
}
