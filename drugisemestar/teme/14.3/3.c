#include <stdio.h>
#include <stdlib.h>

void greska();
void print_bits(unsigned x);
unsigned razmeni_blokove(unsigned x, int i, int j, int k);

int main()
{
    unsigned x;
    int i, j, k;
    scanf("%u%d%d%d", &x, &i, &j, &k);
    if(abs(i-j) < k || i < 0 || j < 0 || k < 0|| i + k > (int)(8*sizeof(unsigned)) || j + k > (int)(8*sizeof(unsigned))) 
        greska();
        
    unsigned rez = razmeni_blokove(x, i, j, k);
    printf("%u\n", rez);

    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void print_bits(unsigned x)
{
    unsigned mask = 1 << (8*sizeof(unsigned) - 1);
    int i = 1;
    while (mask)
    {
        putchar((x & mask)? '1' : '0');
        mask >>= 1;
        if (i % 4 == 0)
        {
            putchar(' ');
        }
        i++;
    }
    putchar('\n');
}

unsigned razmeni_blokove(unsigned x, int i, int j, int k)
{
    unsigned mask_i = 0, mask1 = 1 << i;
    int l;
    for (l = k; l; l--)
    {
        mask_i |= x & mask1;
        mask1 <<= 1;
    }

    unsigned mask_j = 0, mask2 = 1 << j;
    for (l = k; l; l--)
    {
        mask_j |= x & mask2;
        mask2 <<= 1;
    }

    unsigned rez = x;
    rez ^= mask_i;
    rez ^= mask_j;

    if (j > i)
    {
        mask_i <<= j - i;
        mask_j >>= j - i;
    }
    else
    {
        mask_i >>= i - j;
        mask_j <<= i - j;
    }
    
    
    
    rez |= mask_i;
    rez |= mask_j;

    return rez;
}