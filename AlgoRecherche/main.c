#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include "algo.h"




int main(void){

    char x[100];
    char y[100]; 
    printf("\n\nEntrez le mot a chercher : ");
    scanf("%s",x);
    printf("\n\nEntrez le mot dans lequelle vous voulez chercher : ");
    scanf("%s",y);
    printf("\n ******  algorithme na¨ıf, avec boucle interne, sans boucle rapide, sans sentinelle  ****** ");
    printf("\nNbr d'occurences de %s dans %s est --> %d \n\n",x,y,algoNaifIntern(x,strlen(x),y,strlen(y)));
    printf("\n ******   algorithme na¨ıf, avec boucle interne, avec boucle rapide, sans sentinelle  ****** ");
    printf("\nNbr d'occurences de %s dans %s est --> %d \n\n",x,y,algoNaifInternRapide(x,strlen(x),y,strlen(y)));

    return 0;
}