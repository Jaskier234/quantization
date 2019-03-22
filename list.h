#ifndef list_h
#define list_h

#include <stdint.h>
#include "trie.h"

// This module is used to track equivalence classes, and energy values of
// histrories

struct List;

// Element is a representant of history in a List
typedef struct Element
{
    struct Element *prev, *next;
    struct List *list;
} Element;


typedef struct List
{
    int size;
    uint64_t *energy;
    Element *begin, *end;
} List;

// Creates list with one element and returns pointer to that element(not list)
Element *createList();

// Removes Element from list and deallocates memory. If then List is empty also
// deallocates List
void freeElement(Element*);

// Merge function takes as an arguments pointers to Elements and merges Lists
// associated with these elements
void merge(Element*, Element*);

#endif // list_h
