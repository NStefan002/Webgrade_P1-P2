#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAKS_DUZINA_NISKE (255+1) /* 255 karaktera i jos 1 za terminalnu nulu */

int najcesci_karakter(char s[])
{
    /***POCETAK KODA***/

    /***KRAJ KODA***/
}

int main()
{
    char s[MAKS_DUZINA_NISKE];
    char formatNiska[32];
    sprintf(formatNiska, "%%%ds", MAKS_DUZINA_NISKE-1);
    scanf(formatNiska, s);
    printf("%c\n", (char)najcesci_karakter(s));
    return 0;
}
