#ifndef TRIE_H
#define TRIE_H

struct _list {
int startNode; /* etat de depart de la transition */
int targetNode; /* cible de la transition */
unsigned char letter; /* etiquette de la transition */
struct _list *next; /* maillon suivant */
};
typedef struct _list *List;
struct _trie {
int maxNode; /* Nombre maximal de noeuds du trie */
int nextNode; /* Indice du prochain noeud disponible */
List *transition; /* listes d’adjacence */
char *finite; /* etats terminaux */
};
typedef struct _trie *Trie;

void affichageEnsemble(unsigned char **ensemble,int cardinal);

void freeEnsemble(unsigned char **ensemble,int cardinal);

int calculMaxNode(unsigned char **ensemble,int cardinal);

Trie createTrie(int maxNode);

void affichageTrie(Trie trie);

void freeTrie(Trie trie);

void insertInTrie(Trie trie, unsigned char *w);

int isInTrie(Trie trie, unsigned char *w);

Trie prefixTrie(unsigned char *mot);

Trie suffixTrie(unsigned char *mot);

Trie facteurTrie(unsigned char *mot);

#endif 
