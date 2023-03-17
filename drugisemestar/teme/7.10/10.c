#include <stdio.h>
#include <stdlib.h>

void greska();
int strogo_rastuce(int x);

int main(int argc, const char* argv[])
{
    int br_strogo_rastucih = 0;
    int x, i;

    for(i = 1; i < argc; i++) {
        x = atoi(argv[i]);
        if(strogo_rastuce(x))
            br_strogo_rastucih++;
    }

    printf("%d\n", br_strogo_rastucih);
    
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int strogo_rastuce(int x)
{
    x = (x < 0)? -x : x;
    while(x) {
        if(x%10 <= (x%100)/10)
            return 0;
        
        x /= 10;
    }

    return 1;
}