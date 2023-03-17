#include <stdio.h>
#include <stdlib.h>

void greska();
unsigned invertujSvakiTreci(unsigned x);

int main()
{
    unsigned x;
    scanf("%u", &x);

    printf("%u\n", invertujSvakiTreci(x));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

unsigned invertujSvakiTreci(unsigned x)
{
    unsigned n = 8*sizeof(unsigned) - (8*sizeof(unsigned))%3;
    unsigned jedinica = 1 << n;
    while (jedinica)
    {
        if (x & jedinica)
        {
            x -= jedinica;
        }
        else
        {
            x += jedinica;
        }
        jedinica >>= 3;
    }
    return x;
}