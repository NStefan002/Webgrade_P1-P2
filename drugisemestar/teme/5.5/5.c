#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

void greska();
char* podniska(char* s1, char* s2);

int main()
{
    char s1[MAX], s2[MAX];
    scanf("%s%s", s1, s2);

    // rezultat f-je smestamo u posebnu promenljivu da ne bi vise puta pozivali f-ju
    char* rezultat = podniska(s1, s2);

    if(NULL == rezultat)
        puts("-1");
    else
        printf("%ld\n", rezultat - s2);

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

char* podniska(char* s1, char* s2)
{
    if(strlen(s1) > strlen(s2))
        return NULL;
    
    char* adresa = podniska(s1, s2+1);
    if(*s1 == *s2)
        if(strncmp(s1, s2, strlen(s1)) == 0)
            adresa = s2;
    
    return adresa;
}