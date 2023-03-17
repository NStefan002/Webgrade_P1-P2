#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc==1) {
        printf("-1\n");
        return 1;
    }
    int i, j, brm=0, brv=0;
    for(i=1; i<argc; i++) {
        for(j=0; argv[i][j]; j++) {
            if(islower(argv[i][j]))
                brm++;
            if(isupper(argv[i][j]))
                brv++;
        }
    }
    if(brv>brm)
        printf("A\n");
    else if(brm>brv)
        printf("a\n");
    else printf("0\n");
}
