#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAKS_DUZINA_NISKE (255+1) /* 255 karaktera i jos 1 za terminalnu nulu */

int najcesci_karakter(char s[])
{
    /***POCETAK KODA***/
    int ponavljanja[128] = {};
    int i;
    for(i = 0; s[i]; i++) {
        ponavljanja[(int)s[i]]++;
    }

    int max = 0, indeks = 0;
    for(i = 0; i < 128; i++) {
        if(max < ponavljanja[i]) {
            max = ponavljanja[i];
            indeks = i;
        }   
    }

    return indeks;
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
