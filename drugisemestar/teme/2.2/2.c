#include <stdio.h>
#include <stdlib.h>

void greska();

int main(int argc, char* argv[]) {
    // provera broja argumenata
    if(argc != 2)
        greska();

    // otvaranje datoteke
    FILE* f;
    f = fopen(argv[1], "r");
    if(NULL == f)
        greska();
    
    // provera da li su zagrade uparene
    char c;
    int br_otv = 0, br_zatv = 0;
    while((c = fgetc(f)) != EOF) {
        if(c == '(')
            br_otv++;
        else if(c == ')')
            br_zatv++;

        if(br_zatv > br_otv ) 
            break;
    }
    if(br_otv == br_zatv)
        printf("jesu\n");
    else
        printf("nisu\n");

    // zatvaranje datoteke
    fclose(f);
    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}