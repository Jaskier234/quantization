#ifndef trie_h
#define trie_h

#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

// This module keeps track of which histories are declared

typedef struct Node
{
    struct Node *next[4];
    struct Element *energyClass;// representant of history in List
} Node;

Node trieDefault;

// Adds new history to tree
void insert(Node* tree, char* history);

// Removes history from tree
void del(Node* tree, char* history);

// Checks if history is already in tree
bool declared(Node* tree, char* history);

// Deallocates all Nodes in subtree
void freeNode(Node* tree);

// returns Element associated with history
struct Element *listElem(Node* tree, char* history);

#endif // trie_h
