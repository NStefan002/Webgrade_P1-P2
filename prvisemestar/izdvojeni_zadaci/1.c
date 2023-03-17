#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned obrni(unsigned x)
{
    /***POCETAK KODA***/
    x=x/10000+(x/1000%10)*10+(x/100%10)*100+(x/10%10)*1000+(x%10)*10000;
    return x;
    /***KRAJ KODA***/
}

int main()
{
    unsigned x;
    scanf("%u", &x);
    if (x < 10000 || x > 99999) {
        fprintf(stderr, "Niste uneli petocifren broj!\n");
        exit(EXIT_FAILURE);
    }
    
    printf("%u\n", obrni(x));
    return 0;
}
