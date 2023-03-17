#include <stdio.h>

int main() {
    char a[7];
    for (int i=0; i<7; i++) 
        a[i]=getchar();
    if (a[0]!='m' || (a[1]!='i' && a[1]!='a' && a[1]!='r' && a[1]!='s' && a[1]!='m' && a[1]!='p') || a[2,3,4,5,6]<'0' || a[2,3,4,5,6]>'9') {
        printf("-1\n");
        return 1;
    }
    switch (a[1]) {
        case('i'):
            printf("informatika\n");
            break;
        case('a'):
            printf("astronomija\n");
            break;
        case('r'):
            printf("racunarstvo i informatika\n");
            break;
        case('s'):
            printf("statistika\n");
            break;
        case('m'):
            printf("teorijska matematika\n");
            break;
        case('p'):
            printf("primenjena matematika\n");
            break;
    }
    if (a[2]>='3') {
        printf("%d/19%c%c", (a[4]-'0')*100 + (a[5]-'0')*10 + (a[6]-'0'), a[2], a[3]);
        return 0;
    } else  {
        printf("%d/20%c%c", (a[4]-'0')*100 + (a[5]-'0')*10 + (a[6]-'0'), a[2], a[3]);
        return 0;
    }
}
