#include <stdio.h>
#include <stdlib.h>

void greska();
unsigned invertuj(unsigned x, unsigned k);

int main()
{
    unsigned x, k;
    scanf("%u%u", &x, &k);

    printf("%u\n", invertuj(x, k));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

unsigned invertuj(unsigned x, unsigned k)
{
    unsigned jedinica = 1;
    unsigned br_jedinica = 0;

    while (jedinica != 1U << (8*sizeof(unsigned)))
    {
        if (x & jedinica)
        {
            br_jedinica++;
        }
        if(br_jedinica == k)
        {
            x -= jedinica;
            br_jedinica = 0;
        }
        jedinica <<= 1;
    }
    
    return x;
}