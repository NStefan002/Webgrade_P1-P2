#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc==1) {
        printf("-1\n");
        return 1;
    }
    int i, max=strlen(argv[1]);
    for(i=2; i<argc; i++) {
        if(strlen(argv[i])>max)
            max=strlen(argv[i]);
    }
    printf("%d\n", max);
}
