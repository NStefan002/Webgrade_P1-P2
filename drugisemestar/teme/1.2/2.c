#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_IME 21

void greska();

int main() {
    char ime[MAX_IME];
    scanf("%s", ime);
    
    FILE* f;
    f = fopen(ime, "r");
    if(NULL == f)
        greska();
    
    char c;
    int ponavljanja[10] = {0};
    while((c = fgetc(f)) != EOF) {
        if(isdigit(c))
            ponavljanja[c - '0']++;
    }

    int i, max = 0, broj;
    for(i = 0; i < 10; i++) {
        if(max < ponavljanja[i]) {
            max = ponavljanja[i];
            broj = i;
        }
    }

    if(max)
        printf("%d\n", broj);
    else
        printf("-1\n");

    fclose(f);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}