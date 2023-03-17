#include <stdio.h>
#include <stdlib.h>

#define MAX 64

void greska();
int poredi(char* s1, char* s2);

int main()
{
    // ucitavnje niski
    char niska1[MAX], niska2[MAX];
    while(scanf("%s%s", niska1, niska2) != EOF) {
        printf("%d\n", poredi(niska1, niska2));
    }
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int poredi(char* s1, char* s2)
{
    if(*s1 == '\0' && *s2 == '\0')
        return 0;
    
    if(*s1 == '\0')
        return 1;
    
    if(*s2 == '\0')
        return 1;
    
    int rez = poredi(s1+1, s2+1);

    if(rez == 1)
        return rez;

    if(*s1 == *s2)
        rez = 0;
    else
        rez = 1;
    return rez;
}