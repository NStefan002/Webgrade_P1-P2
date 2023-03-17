#include <stdio.h>
#include <stdlib.h>

void greska();
unsigned sekvenca(unsigned x);

int main()
{
    unsigned x;
    scanf("%u", &x);

    printf("%u\n", sekvenca(x));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

unsigned sekvenca(unsigned x)
{
    unsigned jedinica = 2 << (8*sizeof(unsigned)-3);  // 010 0...0
    unsigned sekvenca = 7 << (8*sizeof(unsigned)-3);  // 111 0...0
    unsigned br = 0;

    while (sekvenca != 3)   // 0...0 11
    {
        if ((x & sekvenca) == jedinica)
        {
            br++;
        }
        
        jedinica >>= 1;
        sekvenca >>= 1;
    }

    return br;
}