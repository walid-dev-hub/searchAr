#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <stddef.h> 
#include <limits.h> 
#include <string.h>
#include "trie.h"


void affichageEnsemble(unsigned char **ensemble,int cardinal){
    for(int i=0;i<cardinal;i++){
        printf("\nMot numéro %d : %s",i,(char *)ensemble[i]);
    }
    printf("\n");
    return;
}

void freeEnsemble(unsigned char **ensemble,int cardinal){
    for(int i=0;i<cardinal;i++){
        free(ensemble[i]);
    }
    free(ensemble);
    return;
}

int calculMaxNode(unsigned char **ensemble,int cardinal){//extraire maxNode depuis l'ensemble de mots fournie
    int maxNode = 0;
    for(int i=0;i<cardinal;i++){
        maxNode += strlen((char*)ensemble[i]);
    }
    return maxNode+1; 
}

static void initFinite(char *finite,int maxNode){ //j'initialise le tableau d'état finaux à 0 donc pas d'état finle en ce moment.
    for(int i=0;i<maxNode;i++){
        finite[i]=0;
    }
    return;
}

static void initTransition(int **transition,int maxNode){ //j'initialise la matrice de transitions à -1 pas de transition existante.
    for(int i=0;i<maxNode;i++){
        for(int j=0;j<=UCHAR_MAX;j++){
            transition[i][j]=-1;
        }
    }
    return;
}

static void affichageFinite(char *finite,int maxNode){
    printf("\nTable des finaux : \n");
    printf("ÉTAT -> Finale?\n\n"); 
    for(int i=0;i<maxNode;i++){
        printf("%d -> %d\n",i,finite[i]);
    }
    return;
}

static void freeFinite(char *finite){
    free(finite);
    return;
}

static void affichageTransition(int **transition,int maxNode){ 
    printf("\nTable de transition : \n");
    for(int i=0;i<maxNode;i++){
        for(int j=0;j<=UCHAR_MAX;j++){
            if(transition[i][j]!=-1){
                printf("\n%d -> %c -> %d\t",i,j,transition[i][j]);
            }
        }
    }
    printf("\n");
    return;
}

void affichageTrie(Trie trie){
    printf("\n\n***************** Trie *****************");
    printf("\n\nNombre d'état crées est %d",trie->nextNode);
    affichageTransition(trie->transition,trie->maxNode);
    affichageFinite(trie->finite,trie->maxNode);
    
}

static void freeTransition(int **transition,int maxNode){
    for(int i=0;i<maxNode;i++){
        free(transition[i]);
    }
    free(transition);
    return;
}


Trie createTrie(int maxNode){
    Trie t = malloc(sizeof(struct _trie));
    t->maxNode = maxNode ;
    t->nextNode = 1 ; // j'ai mis 1 car la racine (0) est tjrs a epsilon.
    t->transition = malloc(maxNode*sizeof(int*)); 
    for(int i=0;i<maxNode;i++){
        t->transition[i]= malloc((UCHAR_MAX+1)*sizeof(int));// j'ai ajouté 1 car UCHAR_MAX est 255 (0 ... 255) donc 256 valeur sinon on obtient 255 valeur
    }
    t->finite = malloc(maxNode*sizeof(char));
    initTransition(t->transition,maxNode);
    initFinite(t->finite,maxNode);
    return t;
}

void freeTrie(Trie trie){
    freeTransition(trie->transition,trie->maxNode);
    freeFinite(trie->finite);
    free(trie);
    return;
}

void insertInTrie(Trie trie, unsigned char *w){
    int i=0;
    int state = 0; 
    int taille = strlen((char *)w);
    while(i<taille && (trie->transition[state][w[i]]) != -1){
        state = trie->transition[state][w[i]];
        i++;
    }
    if (i==taille&&trie->finite[state]==1){
        printf("\n Le mot %s existe déja !",w);
    }else{
        for(;i<taille;i++){
            trie->transition[state][w[i]] = trie->nextNode;
            state = trie->nextNode;
            trie->nextNode++;
        }
    }    
    if(trie->finite[state] == 0) trie->finite[state]=1; 
    
    return; 
}

int isInTrie(Trie trie, unsigned char *w){
    int taille = strlen((char *)w);
    int i = 0,state=0;
    while(i<taille){
        if(trie->transition[state][w[i]] != -1){
            state = trie->transition[state][w[i]];
            i++;
        }else{
            break;
        }
    }
    if(i == taille){
        if(trie->finite[state]==1){
            return 1;
        }
    }
    return 0;
}

Trie prefixTrie(unsigned char *mot){
    Trie prTrie = NULL;
    int taille = strlen((char *)mot);
    int maxNode = taille+1; //tjrs plus la racine
    
    prTrie=createTrie(maxNode);
    prTrie->finite[0]=1;//pour epsilon
    for(int i=0;i<taille;i++){
        char pref[i+2];
        for(int j=0;j<=i;j++){
            pref[j]=mot[j];
        }
        pref[i+1]='\0';
        insertInTrie(prTrie,(unsigned char *)pref);
    }
    return prTrie;
}


Trie suffixTrie(unsigned char *mot){
    
    int taille=strlen((char *)mot);
    int maxNode = 0;
    for(int i=1;i<=taille;i++){
        maxNode += i; 
    }
    maxNode ++; //pour la racine
    Trie sfTrie = createTrie(maxNode);
    for(int i = taille-1;i>=0;i--){
        char suff[taille-i+1];
        for(int j=0,l=i;(j<taille-i)&&(l<taille);j++,l++){
            suff[j]=mot[l];
        }
        suff[taille-i] = '\0';
        insertInTrie(sfTrie,(unsigned char *)suff);
    }
    sfTrie->finite[0]=1;
    return sfTrie;
}

Trie facteurTrie(unsigned char *mot){
    int taille=strlen((char *)mot);
    int maxNode = 0;
    for(int i=1;i<=taille;i++){
        maxNode += i; 
    }
    maxNode ++; //pour la racine
    Trie ftTrie = createTrie(maxNode);
    for(int i=0;i<taille;i++){
        char fact[taille-i+1];
        for(int j=0,l=i;l<taille;j++,l++){
            fact[j]=mot[l];
        }
        fact[taille-i]='\0';
        insertInTrie(ftTrie,(unsigned char *)fact);
    }
    for(int i=0;i<ftTrie->nextNode;i++){
        ftTrie->finite[i]=1;
    }
    return ftTrie;
}





