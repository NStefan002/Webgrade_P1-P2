#include <stdio.h>
#include <stdlib.h>

unsigned povrsina_pravougaonika(int x1, int y1, int x2, int y2)
{
    /***POCETAK KODA***/
    int r;
    r=abs(x1-x2)*abs(y1-y2);
    return r;
    /***KRAJ KODA***/
}

int main()
{
    int x1; 
    int y1; 
    int x2;
    int y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%u\n", povrsina_pravougaonika(x1, y1, x2, y2));
    return 0;
}
