#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int min3(int br1, int br2, int br3)
{
    /***POCETAK KODA***/
    int min=br1;
    if (min>br2) min=br2;
    if (min>br3) min=br3;
    return min;
    /***KRAJ KODA***/
}

int main()
{
    int br1; 
    int br2; 
    int br3;
    scanf("%d%d%d", &br1, &br2, &br3);
    printf("%d\n", min3(br1, br2, br3));
    return 0;
}
