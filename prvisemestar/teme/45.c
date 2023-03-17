#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11

typedef struct{
    char figura[MAX];
    int red;
    char kolona;
}SAH;

int napada(SAH* f1, SAH* f2) {
    f1->kolona=f1->kolona-'a'+1;
    f2->kolona=f2->kolona-'a'+1;
    if(!strcmp(f1->figura, "kraljica"))
        if((f1->red==f2->red) || (f1->kolona==f2->kolona) || ((abs(f1->red - f2->red)==abs(f1->kolona - f2->kolona)))) 
                return 1;
            else return 0;
    else if(!strcmp(f1->figura, "lovac"))
        if((abs(f1->red - f2->red)==abs(f1->kolona - f2->kolona)))
            return 1;
        else return 0;
    else if(!strcmp(f1->figura, "top"))
        if((f1->red==f2->red) || (f1->kolona==f2->kolona))
            return 1;
        else return 0;
    else if(!strcmp(f1->figura, "konj"))
        if((abs(f1->red - f2->red)==1 && abs(f1->kolona - f2->kolona)==2) || (abs(f1->red - f2->red)==2 && abs(f1->kolona - f2->kolona)==1))
            return 1;
        else return 0;
}

int main() {
    SAH f1, f2;
    scanf("%s %d %c", f1.figura, &f1.red, &f1.kolona);
    scanf("%s %d %c", f2.figura, &f2.red, &f2.kolona);
    printf("%d %d\n", napada(&f1, &f2), napada(&f2, &f1));
}
