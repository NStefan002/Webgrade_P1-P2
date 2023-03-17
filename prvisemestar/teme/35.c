#include <stdio.h>
#include <ctype.h>
#define MAX 101

int sifrovanje_slova(char c);

int main() {
    int i;
    char s[MAX];
    scanf("%s", s);
    for (i=0; s[i]; i++) {
        if(islower(s[i]) || isupper(s[i])) {
            s[i]=sifrovanje_slova(s[i])+'0';
//             printf("%d", sifrovanje_slova(s[i]));
        }
        else if(isdigit(s[i]))
            s[i]='a'+s[i]-'0';
    }
    printf("%s\n", s);
}

int sifrovanje_slova(char c) {
    int p=0;
    while(c) {
        p+=c%10;
        c/=10;
    }
    while(p/10) {
        p=p/10+p%10;
    }
    return p;
}
