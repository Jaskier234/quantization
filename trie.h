#ifndef trie_h
#define trie_h

#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node *next[4];
    // bool declared; // czy potrzebne?
} Node;

Node trieDefault;

void insert(Node*, char*);
void del(Node*, char*);
bool declared(Node*, char*);

#endif // trie_h
