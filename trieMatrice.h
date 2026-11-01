#ifndef TRIEMATRICE_h
#define TRIEMATRICE_h

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

void initFinite(char *finite,int maxNode);

void initTransition(int **transition,int maxNode);

void affichageFinite(char *finite,int maxNode);

void affichageTransition(int **transition,int maxNode);

Trie createTrie(int maxNode);

void insertInTrie(Trie trie, unsigned char *w);

int isInTrie(Trie trie, unsigned char *w); 

void freeFinite(char *finite);

void freeTransition(int **transition,int maxNode);

void freeTrie(Trie trie);

Trie prefixTrie(unsigned char *mot);




#endif 