#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include "algo.h"

int boucleRapide(char c,char *y,int indice,int tailleY){
    while(y[indice]!=c && indice<tailleY){
        indice++;
    }
    return indice;
}
int algoNaifIntern(char *x,int m,char *y,int n){
    int occ=0;
    int j=0;
    for(int i=0;i<n;i++){
        while(j<m && (j+i)<n && x[j]==y[j+i]){
            j++;
        }
        if(j == m ) occ++;
        j=0;
    }
    return occ; 
}



int algoNaifInternRapide(char *x,int m,char *y,int n){
    int occ=0;
    int j=0,i=0;
    char c = x[0];
    while(i<n){
        i = boucleRapide(x[j],y,i,n);
        if(i<n){
            j++;  
            while(j<m && (j+i)<n && x[j]==y[j+i]){
                j++;
            }
            if(j == m ) occ++;
            j=0;
        }
    }
    return occ; 
}