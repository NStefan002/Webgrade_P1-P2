#include <stdio.h>
#include <stdlib.h>

#define MAX 64

void greska();
char* sadrzi(char* s, char c);

int main()
{
    // ucitavanje niske i karaktera
    char niska[MAX], karakter;
    scanf("%s %c", niska, &karakter);

    /* pokazivac na mesto karaktera "spakovan" u promenljivu
    (da ne bi vise puta pozivali f-ju) */
    char* rezultat = sadrzi(niska, karakter);
    if(NULL == rezultat)
        puts("-1");
    else
        printf("%ld\n", rezultat - niska);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

char* sadrzi(char* s, char c)
{
    if(*s == '\0')
        return NULL;
        
    char* pozicija = sadrzi(s+1, c);
    if(*s == c) 
        pozicija = s;
    
    return pozicija;
}