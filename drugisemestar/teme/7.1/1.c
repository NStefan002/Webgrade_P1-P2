#include <stdio.h>
#include <stdlib.h>

void greska();
int izmeni(int n);

int main(int argc, const char* argv[])
{
    // provera broja argumenata
    if(argc != 2)
        greska();
    
    int n = atoi(argv[1]);
    
    printf("%d\n", izmeni(n));

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int izmeni(int n)
{
    if(n == 0)
        return n;
    
    int novi_broj = izmeni(n/10);

    if(n%2 == 0)
        return novi_broj*10 + (n%10)/2;
    
    return novi_broj*10 + n%10;
}