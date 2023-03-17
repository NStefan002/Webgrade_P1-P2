#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned suma_kubova_cifara(unsigned x)
{
    /***POCETAK KODA***/

    /***KRAJ KODA***/
}

int main()
{
    unsigned x;
    scanf("%u", &x);
    if (x < 1000 || x > 9999) {
        fprintf(stderr, "Niste uneli cetvorocifren broj!\n");
        exit(EXIT_FAILURE);
    }
    
    printf("%u\n", suma_kubova_cifara(x));
    return 0;
}
