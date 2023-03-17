#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void greska();
void m(char* s);
void v(char* s);
void mv(char* s);
void stampaj(void (*fp)(void*), char* s);

int main(int argc, char* argv[])
{
    // provera broja i ispravnosti argumenata
    if(argc != 3)
        greska();
    if(strlen(argv[1]) > 3)
        greska();
    if(argv[1][0] != '-' || (argv[1][1] != 'm' && argv[1][1] != 'v'))
        greska();
    if(argv[1][2] && argv[1][2] != 'v')
        greska();

    // poziv odgovarajuce f-je
    void (*fp)(void*);

    if(argv[1][2] == 'v')
        fp = &mv;
    
    else if(argv[1][1] == 'm')
        fp = &m;
    else
        fp = &v;

    stampaj(fp, argv[2]);

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void m(char* s)
{
    for(int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

void v(char* s)
{
    for(int i = 0; s[i]; i++) {
        s[i] = toupper(s[i]);
    }
}

void mv(char* s)
{
    for(int i = 0; s[i]; i++) {
        if(islower(s[i]))
            s[i] = toupper(s[i]);
        else if(isupper(s[i]))
            s[i] = tolower(s[i]);
    }
}

void stampaj(void (*fp)(void*), char* s)
{
    fp(s);
    printf("%s\n", s);
}