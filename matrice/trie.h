#ifndef TRIE_H
#define TRIE_H

//Déclarations des variables et structures 

struct _trie {
int maxNode; /* Nombre maximal de noeuds du trie */
int nextNode; /* Indice du prochain noeud disponible */
int **transition; /* matrice de transition */
char *finite; /* etats terminaux */
};
typedef  struct _trie *Trie; 
//Fonctions : 

void affichageEnsemble(unsigned char **ensemble,int cardinal);

void freeEnsemble(unsigned char **ensemble,int cardinal);

int calculMaxNode(unsigned char **ensemble,int cardinal);

void affichageTrie(Trie trie);

Trie createTrie(int maxNode);

void insertInTrie(Trie trie, unsigned char *w);

int isInTrie(Trie trie, unsigned char *w); 

void freeTrie(Trie trie);

Trie prefixTrie(unsigned char *mot);

Trie facteurTrie(unsigned char *mot);

Trie suffixTrie(unsigned char *mot);

#endif 