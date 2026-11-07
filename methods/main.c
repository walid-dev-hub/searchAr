#include <stdio.h> 
#include <stdlib.h> 
#include <stddef.h>
#include <string.h>
#include <limits.h>
#include "trie.h"

static unsigned char **ensemble = NULL;  
static unsigned char cardinal =  0 ;
static int maxNode = 0;
static char test[100];
static char p;
int main(void){
    
   printf("\nBienvenue dans searchAr, Bienvenue dans le monde des mots !!!\n\n");

    prog:
    printf("\n\nChoisissez le mode qui vous convient :");
    printf("\ne : Trie d'un ensemble de mots - p : trie des préfixes d'un mot\ns : trie des suffixes d'un mot - f : trie des facteurs d'un mot\nq : quitter le programme");
    printf("\n--> : ");
    scanf(" %c",&p);
    switch (p){
        case 'e': goto Mensemble;
        break;
        case 'p':goto Mprefix;
        break; 
        case 's':goto Msuffix;
        break; 
        case 'f':goto Mfacteur;
        break; 
        case 'q':goto finish;
        break;
        default : goto prog;
        break;  
    }

    Mensemble:

    printf("\nSaisissez le nombre de mots de l'ensemble : ");
    scanf("%hhu",&cardinal);
    ensemble = malloc(cardinal*sizeof(unsigned char *));
    printf("\nEntrez votre ensemble des mots : ");
    for(int i=0;i<cardinal;i++){
        char mot[100];
        printf("\nMot numéro %d : ",i+1); 
        printf("\nEntrez le mot : ");
        scanf("%99s",mot);
        ensemble[i] = malloc ((strlen(mot)+1)*sizeof(unsigned char));
        strcpy((char*)ensemble[i],mot);
    }
    maxNode = calculMaxNode(ensemble,cardinal);
    printf("\nmaxNode : %d",maxNode);
    Trie t=createTrie(maxNode);
    for(int i=0;i<cardinal;i++){
        insertInTrie(t,ensemble[i]);
    }
    affichageEnsemble(ensemble,cardinal);
    affichageTrie(t);
    //test d'existance
    testE:

    printf("\nTestes si un mot existe dans le trie !!!\n\n");
    printf("\nEntrez un mot : "); 
    scanf("%99s",test);
    if(isInTrie(t,(unsigned char *)test)== 1)  printf("\nLe mot \"%s\" existe dans le trie :)",test);
    else{
        printf("\nle mot \"%s\" n'existe pas dans la trie donc il appratient pas à l'ensemble !!!",test);
    }
    printf("\n\nChoisissez le mode qui vous convient :");
    printf("\nt : Test d'existance d'un mot dans l'ensemble - m : Menu - q : quitter");
    printf("\n--> : ");
    scanf(" %c",&p);
    switch (p){
        case 't': goto testE;
        break;
        case 'm': freeEnsemble(ensemble,cardinal); freeTrie(t); goto prog;
        break; 
        case 'q':  freeEnsemble(ensemble,cardinal); freeTrie(t); goto finish;
        break; 
        default :  freeEnsemble(ensemble,cardinal); freeTrie(t); goto prog;
        break;  
    }

    Mprefix:
   
    char testPre[100];
    printf("\nEntrez un mot et construit le trie de ses préfixes!!");
    printf("\n--> : ");
    scanf("%99s",testPre);
    Trie prTrie = prefixTrie((unsigned char *)testPre);
    printf("\nLe trie des préfixes de mot \"%s\" est prete!",(char *)testPre);
    affichageTrie(prTrie);
    
    //test d'existance d'un mot dans le trie
    testP: 

    printf("\nTestes si un mot existe dans le trie !!!\n\n");
    printf("\nEntrez un mot : "); 
    scanf("%99s",test);
    if(isInTrie(prTrie,(unsigned char *)test)== 1)  printf("\nLe mot \"%s\" existe dans le trie :)",test);
    else{
        printf("\nle mot \"%s\" n'existe pas dans la trie donc il appratient pas à l'ensemble !!!",test);
    }
    printf("\n\nChoisissez le mode qui vous convient :");
    printf("\nt : Test d'existance d'un mot dans l'ensemble - m : Menu - q : quitter");
    printf("\n--> : ");
    scanf(" %c",&p);
    switch (p){
        case 't': goto testP;
        break;
        case 'm': freeTrie(prTrie); goto prog;
        break; 
        case 'q':freeTrie(prTrie); goto finish;
        break; 
        default : freeTrie(prTrie); goto prog;
        break;  
    }

    Msuffix:
    
    char testSuff[100];
    printf("\nEntrez un mot et construit le trie de ses suffixes!!");
    printf("\n--> : ");
    scanf("%99s",testSuff);
    Trie sfTrie = suffixTrie((unsigned char *)testSuff);
    printf("\nLe trie des suffixes de mot \"%s\" est prete!",(char *)testSuff);
    affichageTrie(sfTrie);

    //test d'existance d'un mot dans le trie
    testS:

    printf("\nTestes si un mot existe dans le trie !!!\n\n");
    printf("\nEntrez un mot : "); 
    scanf("%99s",test);
    if(isInTrie(sfTrie,(unsigned char *)test)== 1)  printf("\nLe mot \"%s\" existe dans le trie :)",test);
    else{
        printf("\nle mot \"%s\" n'existe pas dans la trie donc il appratient pas à l'ensemble !!!",test);
    }
    printf("\n\nChoisissez le mode qui vous convient :");
    printf("\nt : Test d'existance d'un mot dans l'ensemble - m : Menu - q : quitter");
    printf("\n--> : ");
    scanf(" %c",&p);
    switch (p){
        case 't': goto testS;
        break;
        case 'm':freeTrie(sfTrie); goto prog;
        break; 
        case 'q': freeTrie(sfTrie); goto finish;
        break; 
        default : freeTrie(sfTrie); goto prog;
        break;  
    }


    Mfacteur:
    
    char testFact[100];
    printf("\nEntrez un mot et construit le trie de ses facteurs!!");
    printf("\n--> : ");
    scanf("%99s",testFact);
    Trie ftTrie = facteurTrie((unsigned char *)testFact);
    printf("\nLe trie des facteurs de mot \"%s\" est prete!",(char *)testFact);
    affichageTrie(ftTrie);

    //test d'existance d'un mot dans le trie
    testF:

    printf("\nTestes si un mot existe dans le trie !!!\n\n");
    printf("\nEntrez un mot : "); 
    scanf("%99s",test);
    if(isInTrie(ftTrie,(unsigned char *)test)== 1)  printf("\nLe mot \"%s\" existe dans le trie :)",test);
    else{
        printf("\nle mot \"%s\" n'existe pas dans la trie donc il appratient pas à l'ensemble !!!",test);
    }
    printf("\n\nChoisissez le mode qui vous convient :");
    printf("\nt : Test d'existance d'un mot dans l'ensemble - m : Menu - q : quitter");
    printf("\n--> : ");
    scanf(" %c",&p);
    switch (p){
        case 't': goto testF;
        break;
        case 'm': freeTrie(ftTrie); goto prog;
        break; 
        case 'q': freeTrie(ftTrie); goto finish;
        break; 
        default : freeTrie(ftTrie); goto prog;
        break;  
    }

    
    finish://Fin du programme

    printf("\n\nAu revoir :) !\n\n");
    return 0; 
}