#include <stdio.h>
#include <math.h>

int main() {
    char a[11];
    for (int i=0; i<11; i++) {
        scanf("%c", &a[i]);
    }
    if (a[2]%2==0) {
        printf("%d\n", (int)(pow(a[4]-'0',3)+pow(a[5]-'0',3)+pow(a[6]-'0',3)+pow(a[8]-'0',3)+pow(a[9]-'0',3)+pow(a[10]-'0',3)));
        return 0;
    } else {
        printf("%d\n", a[4]+a[5]+a[6]-a[8]-a[9]-a[10]);
        return 0;
    }
}
