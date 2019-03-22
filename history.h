#ifndef history_h
#define history_h

#include "trie.h"

// Adds history to tree
void declare(Node *trie, char *history);

// Checks if history is declared
void valid(Node *trie, char *history);

// Removes history from tree
void delete(Node *trie, char *history);

// Prints history energy
void getEnergy(Node *trie, char *history);

// Changes history energy
void setEnergy(Node *trie, char *history, char *energy);

// Equals two histories
void equal(Node *trie, char *history_a, char *history_b);

#endif // history_h
