#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List listDefault = {1,NULL,NULL,NULL};

Element *createList()
{
    List *list = malloc(sizeof(List));
    Element *begin = malloc(sizeof(Element));
    Element *end = malloc(sizeof(Element));
    Element *elem = malloc(sizeof(Element));
    // *list = {1, -1, begin, end};
    list->size = 1;
    list->energy = NULL;// do poprawienia
    list->begin = begin;
    list->end = end;

    // *begin = {NULL, elem, list};
    begin->prev = NULL;
    begin->next = elem;
    begin->list = list;

    // *elem = {begin, end, list};
    elem->prev = begin;
    elem->next = end;
    elem->list = list;

    // *end = {elem, NULL, list};
    end->prev = elem;
    end->next = NULL;
    end->list = list;

    return elem;
}

void freeElement(Element *elem)
{
    if(elem == NULL)
        return;

    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;
    elem->list->size--;
    if(elem->list->size == 0)
    {
        free(elem->list->end);// pamiętać o energii. może funkcja od tego?
        free(elem->list->begin);
        free(elem->list->energy);
        free(elem->list);
    }
    free(elem);
}

void merge(Element *elem1, Element *elem2)
{
    if(elem1->list == elem2->list)
        return;

    if( false )
    {
        // mniejsza do większej
    }

    List *list1 = elem1->list;
    List *list2 = elem2->list;

    if(list1->energy == NULL && list2->energy != NULL)
    {
        list1->energy = list2->energy;
        list2->energy = NULL;
    }
    else if(list1->energy != NULL && list2->energy != NULL)
        *list1->energy = (*list1->energy + *list2->energy)/2;// overflow

    list1->end->prev->next = list2->begin->next;
    list2->begin->next->prev = list1->end->prev;
    list2->end->prev->next = list1->end;
    list1->end->prev = list2->end->prev;

    list1->size += list2->size;

    Element *elem = list2->begin->next;
    while(elem != NULL)
    {
        elem->list = list1;
        elem = elem->next;
    }

    free(list2->end);
    free(list2->begin);
    free(list2->energy);
    // printf("%p\n", list2->energy);
    free(list2);
}
