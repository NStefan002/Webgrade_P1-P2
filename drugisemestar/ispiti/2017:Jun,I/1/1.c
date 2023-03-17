#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska();
int br_cifara(int x);
int jeste_armstrongov(int x);

int main(int argc, const char* argv[])
{
    // provera broja argumenata
    if (argc != 3)
    {
        greska();
    }

    int a = atoi(argv[1]), b = atoi(argv[2]);
    if (a > b || a < 0)
    {
        greska();
    }
    
    for (int i = a; i <= b; i++)
    {
        if (jeste_armstrongov(i))
        {
            printf("%d ", i);
        }
    }
    putchar('\n');
    
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int br_cifara(int x)
{   
    int br_cif = 0;
    while (x)
    {
        br_cif++;
        x /= 10;
    }

    return br_cif;
}

int jeste_armstrongov(int x)
{
    int suma = 0, br_cif = br_cifara(x), cpx = x;
    while (x)
    {
        suma += (int)pow(x%10, br_cif);
        x /= 10;
    }

    return suma==cpx;
}