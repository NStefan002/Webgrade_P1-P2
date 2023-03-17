#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

void greska();
int broj_pojavljivanja(char* s1, char* s2);

int main()
{
    char s1[MAX], s2[MAX];
    scanf("%s%s", s1, s2);

    printf("%d\n", broj_pojavljivanja(s1, s2));
    
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int broj_pojavljivanja(char* s1, char* s2)
{
    if(strlen(s1) > strlen(s2))
        return 0;
    
    int br_ponavljanja = broj_pojavljivanja(s1, s2+1);
    if(*s1 == *s2)
        if(strncmp(s1, s2, strlen(s1)) == 0)
            return br_ponavljanja + 1;
    return br_ponavljanja;
}