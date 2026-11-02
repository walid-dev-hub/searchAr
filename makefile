CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

all : searchAr_matrice searchAr_hash

searchAr_matrice : main.c matrice/trie.c matrice/trie.h
	$(CC) $(CFLAGS) -Imatrice -o $@ main.c matrice/trie.c

searchAr_hash : main.c hash/trie.c hash/trie.h
	$(CC) $(CFLAGS) -Ihash -o $@ main.c hash/trie.c

clean :
	rm -f searchAr_matrice searchAr_hash a.out

.PHONY : all clean