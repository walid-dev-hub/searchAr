# Chasing words

Implémentation de tries en C :
- trie d'un ensemble de mots,
- trie des préfixes, des suffixes et des facteurs d'un mot.

Deux représentations sont fournies : une **matrice de transitions** et une **table de hachage** (chaînage séparé).

## Prérequis
`gcc` et `make`.

## Compilation
```
git clone <url-du-dépôt>
cd searchAr
make                       # construit les deux versions
make searchAr_matrice      # version matrice seulement
make searchAr_hash         # version table de hachage seulement
make clean                 # supprime les exécutables
```

## Utilisation
```
./searchAr_matrice
./searchAr_hash
```
Menu :
- `e` : trie d'un ensemble de mots
- `p` : trie des préfixes d'un mot
- `s` : trie des suffixes d'un mot
- `f` : trie des facteurs d'un mot
- `q` : quitter

Après la construction, on peut tester si un mot appartient au trie.

## Structure
- `main.c` : programme principal, commun aux deux versions
- `matrice/` : `trie.c`, `trie.h` (matrice de transitions)
- `hash/` : `trie.c`, `trie.h` (table de hachage)
- `makefile`
