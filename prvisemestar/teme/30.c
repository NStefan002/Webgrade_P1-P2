#include <stdio.h>

int konverzija(char x);

int main() {
    char c;
    while(scanf("%c ", &c)!=EOF) {
        printf("%d", konverzija(c));
    }
}

int konverzija(char x) {
    x%=10;
    return x;
}
