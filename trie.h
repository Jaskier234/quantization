#ifndef trie_h
#define trie_h

#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct Node
{
    struct Node *next[4];
    struct Element *energyClass;
} Node;

Node trieDefault;

void insert(Node*, char*);
void del(Node*, char*);
bool declared(Node*, char*);
void freeNode(Node*);
struct Element *listElem(Node*, char*);

#endif // trie_h
