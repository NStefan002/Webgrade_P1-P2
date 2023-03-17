#include <stdio.h>
#include <stdlib.h>

void greska();
unsigned invertovanje(unsigned x, unsigned k, unsigned p);

int main()
{
    unsigned x, k, p;
    scanf("%u%u%u", &x, &k, &p);
    if (k > 8*sizeof(unsigned) || p > 8*sizeof(unsigned))
    {   
        greska();
    }

    printf("%u\n", invertovanje(x, k, p));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

unsigned invertovanje(unsigned x, unsigned k, unsigned p)
{
    unsigned jedinica = 1;
    while (k)
    {
        if (x & jedinica)
        {
            x -= jedinica;
        }
        else
        {
            x += jedinica;
        }
        jedinica <<= 1;
        k--;
    }

    jedinica = 1 << (8*sizeof(unsigned) - 1);
    while (p)
    {
        if (x & jedinica)
        {
            x -= jedinica;
        }
        else
        {
            x += jedinica;
        }
        jedinica >>= 1;
        p--;
    }

    return x;
}