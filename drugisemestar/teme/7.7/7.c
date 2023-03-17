#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska();
int jeste_palindrom(const char* s);

int main(int argc, const char* argv[])
{
    int i, br_palindroma = 0;
    for(i = 1; i < argc; i++) {
        if(jeste_palindrom(argv[i]))
            br_palindroma++;
    }

    printf("%d\n", br_palindroma);


    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int jeste_palindrom(const char* s)
{
    int i, j;
    for(i = 0, j = strlen(s) - 1; i <= j; i++, j--) {
        if(s[i] != s[j])
            return 0;
    }
    return 1;
}