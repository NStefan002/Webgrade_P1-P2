#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int dan;
    int mesec;
    int godina;
} Datum;

Datum sledeci_dan(Datum d)
{
    /***POCETAK KODA***/
    d.dan++; 
   switch(d.mesec) {
       case(2):
           if((d.dan>28 && !(d.godina%4==0 && d.godina%400==0 && d.godina%100!=0)) || (d.dan>29 && (d.godina%4==0 && d.godina%400==0 && d.godina%100!=0))) {
               d.mesec++;
               d.dan=1;
            }
            break;
       case(4):
           if(d.dan>30) {
               d.mesec++;
               d.dan=1;
            }
            break;
        case(6):
           if(d.dan>30) {
               d.mesec++;
               d.dan=1;
            }
            break;
        case(9):
           if(d.dan>30) {
               d.mesec++;
               d.dan=1;
            }
            break;
        case(11):
           if(d.dan>30) {
               d.mesec++;
               d.dan=1;
            }
            break;
       default:
           if(d.dan>31) {
               d.mesec++;
               d.dan=1;
            }
            break;
    }
    if(d.mesec>12) {
        d.godina++;
        d.mesec=1;
    }
    return d;
    /***KRAJ KODA***/
}

int main()
{
    Datum d;
    scanf("%d%d%d", &d.dan, &d.mesec, &d.godina);
    Datum rezultat = sledeci_dan(d);
    printf("%d.%d.%d.\n", rezultat.dan, rezultat.mesec, rezultat.godina);
    return 0;
}
