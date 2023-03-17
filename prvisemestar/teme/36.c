#include <stdio.h>
#include <string.h>
#define MAX 40

int main() {
    char rnk[MAX], podniska[MAX];
    int j=0, i=3, brojac[13]={1,1,1,1,1,1,1,1,1,1,1,1,1};
    scanf("%s", rnk);
    strncpy(podniska, rnk, 3);
    podniska[3]='\0';
     while(i<strlen(rnk)+3) {
         if(rnk[i]==rnk[i-3] && rnk[i+1]==rnk[i-2] && rnk[i+2]==rnk[i-1])            
             brojac[j]++;
         else {
             printf("%d%s", brojac[j], podniska);
             j++;
             podniska[0]=rnk[i];
             podniska[1]=rnk[i+1];
             podniska[2]=rnk[i+2];
             podniska[3]='\0';
         }
//          printf("%s\n", podniska);
//          printf("%d\n", brojac[j]);
         i+=3;
    }
//     printf("%s\n", podniska);
    
    
}
