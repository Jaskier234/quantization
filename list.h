#ifndef list_h
#define list_h

#include "trie.h"

struct List;

typedef struct Element
{
    struct Element *prev, *next;
    struct List *list;
} Element;

typedef struct List
{
    int size;
    long long *energy;// poprawić typ
    Element *begin, *end;
} List;

Element *createList();
void freeElement(Element*);
void merge(Element*, Element*);

// List listDefault;

#endif // list_h
