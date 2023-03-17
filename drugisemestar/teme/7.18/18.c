#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska();
int izmeni_rec(char* s, char c, int n); /* povratna vrednost f-je
predstavlja potvrdu da postoji bar 2 karaktera c u niski s */

int main(int argc, const char* argv[])
{
    if(argc != 4)
        greska();

    char* rec = (char*)malloc(strlen(argv[1]) * sizeof(char));
    if(NULL == rec)
        greska();
    strcpy(rec, argv[1]);

    char karakter = argv[2][0];
    int broj = atoi(argv[3]);

    if(izmeni_rec(rec, karakter, broj))
        printf("%s\n", rec);
    else
        printf("%s\n", argv[1]);

    free(rec);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int izmeni_rec(char* s, char c, int n)
{
    int i, p = 0;
    for(i = 0; s[i]; i++) {
        if(s[i] == c)
            p++;
        if(p == 1 && s[i] != c)
            s[i] += n;
    }

    if(p >= 2)
        return 1;
    
    return 0;
}