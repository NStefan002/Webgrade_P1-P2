#include <stdio.h>
#include <stdlib.h>

void greska();
int izbaci_parne(int x);

int main(int argc, const char* argv[])
{
    // provera broja argumenata
    if(argc != 2)
        greska();

    int broj = atoi(argv[1]);
    printf("%d\n", izbaci_parne(broj));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int izbaci_parne(int x)
{
    if(x == 0)
        return 0;
    
    int novi_broj = izbaci_parne(x/10);

    if(x%2 == 0)
        return novi_broj;
    return novi_broj*10 + x%10;
}