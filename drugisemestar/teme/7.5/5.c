#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

void greska();
void svaka_n_ta(char* ime, int n);

int main(int argc, const char* argv[])
{
    // provera broja argumenata
    if(argc != 3)
        greska();
    
    char rec[MAX];
    strcpy(rec, argv[1]);
    int n = atoi(argv[2]);
    if(n <= 0)
        greska();

    svaka_n_ta(rec, n);

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void svaka_n_ta(char* ime, int n)
{
    // otvaranje datoteke
    FILE* f = fopen(ime, "r");
    if(NULL == f)
        greska();

    char rec[MAX];
    int redni_br_reci = 1;

    while(fscanf(f, "%s", rec) == 1) {
        if(redni_br_reci % n == 0)
            printf("%s ", rec);
        
        redni_br_reci++;
    }
    putchar('\n');

    // zatvaranje datoteke
    fclose(f);
}