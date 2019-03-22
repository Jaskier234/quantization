#include "list.h"

#include <stdlib.h>
#include <inttypes.h>

void initializeElement(Element *elem, Element *prev, Element* next, List *list)
{
    elem->prev = prev;
    elem->next = next;
    elem->list = list;
}

// Creates list with one element and returns pointer to that element(not list)
Element *createList()
{
    List *list = malloc(sizeof(List));
    Element *begin = malloc(sizeof(Element));
    Element *end = malloc(sizeof(Element));
    Element *elem = malloc(sizeof(Element));

    // Cheking if there is enough memory to allocate
    if(list == NULL || begin == NULL || end == NULL || elem == NULL)
    {
        exit(1);
    }

    list->size = 1;
    list->energy = NULL;
    list->begin = begin;
    list->end = end;

    initializeElement(begin, NULL, elem, list);
    initializeElement(elem, begin, end, list);
    initializeElement(end, elem, NULL, list);

    return elem;
}

// Deallocates List
void freeList(List *list)
{
    free(list->end);
    free(list->begin);
    free(list->energy);
    free(list);
}

// Removes Element from list and deallocates memory. If then List is empty also
// deallocates List
void freeElement(Element *elem)
{
    if(elem == NULL)
        return;

    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;
    elem->list->size--;
    if(elem->list->size == 0)
    {
        freeList(elem->list);
    }
    free(elem);
}

// Merge function takes as an arguments pointers to Elements and merges Lists
// associated with these elements
void merge(Element *elem1, Element *elem2)
{
    if(elem1->list == elem2->list)
        return;

    List *list1 = elem1->list;
    List *list2 = elem2->list;

    // Always adds smaller List to bigger
    if( list1->size < list2->size )
    {
        List *temp = list1;
        list1 = list2;
        list2 = temp;
    }

    // Calculating energy of new list
    if(list1->energy == NULL && list2->energy != NULL)
    {
        list1->energy = list2->energy;
        list2->energy = NULL;
    }
    else if(list1->energy != NULL && list2->energy != NULL)
    {
        uint64_t a = *list1->energy;
        uint64_t b = *list2->energy;

        *list1->energy = (a/2) + (b/2);
        if(a%2 == 1 && b%2 == 1)
            (*list1->energy)++;
    }

    // Merging
    list1->end->prev->next = list2->begin->next;
    list2->begin->next->prev = list1->end->prev;
    list2->end->prev->next = list1->end;
    list1->end->prev = list2->end->prev;

    list1->size += list2->size;

    // Updating list field in smaller List
    Element *elem = list2->begin->next;
    while(elem != NULL)
    {
        elem->list = list1;
        elem = elem->next;
    }

    // The other list is no longer needed
    freeList(list2);
}
