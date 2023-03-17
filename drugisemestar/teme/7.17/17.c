#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska();
unsigned long duzina_nove_rec(long unsigned n);
void formiraj_novu_rec(char* nova_rec, const char* stara_rec);

int main(int argc, const char* argv[])
{
    if(argc != 2)
        greska();
    
    char* nova_rec = (char*)malloc(duzina_nove_rec(strlen(argv[1])) * sizeof(char));
    if(NULL == nova_rec)
        greska();
    
    formiraj_novu_rec(nova_rec, argv[1]);
    printf("%s\n", nova_rec);

    free(nova_rec);
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

unsigned long duzina_nove_rec(long unsigned n)
{
    unsigned i, j;
    unsigned long novo_n = 0;
    
    for(i = 1; i <= n; i++) {
        for(j = 0; j < i; j++) {
            novo_n++;
        }
    }

    return novo_n;
}

void formiraj_novu_rec(char* nova_rec, const char* stara_rec)
{
    int i, j, n;
    j= 0;
    for(i = 0; stara_rec[i]; i++) {
        n = i + 1;
        while(n) {
            nova_rec[j] = stara_rec[i];
            j++;
            n--;
        }
    }
}