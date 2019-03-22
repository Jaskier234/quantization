#include "history.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "trie.h"
#include "str.h"

// Adds history to tree
void declare(Node *trie, char *history)
{
    insert(trie, history);
    printf("OK\n");
}

// Checks if history is declared
void valid(Node *trie, char *history)
{
    if(declared(trie, history))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

void delete(Node *trie, char* history)
{
    del(trie, history);
    printf("OK\n");
}

// Prints history energy
void getEnergy(Node *trie, char* history)
{
    Element *elem = listElem(trie, history);
    if(elem == NULL || elem->list->energy == NULL)
        fprintf( stderr, "ERROR\n");
    else
    {
        printf("%" PRIu64 "\n", *elem->list->energy);
    }
}

void setEnergy(Node *trie, char* history, char* energy)
{
    Element *elem = listElem(trie, history);
    if(elem == NULL)
    {
        fprintf( stderr, "ERROR\n");
    }
    else
    {
        if(elem->list->energy == NULL)
        {
            elem->list->energy = malloc(sizeof(uint64_t));
            if(elem->list->energy == NULL)
                exit(1);
        }
        *elem->list->energy = stringToNum(energy);
        printf("OK\n");
    }
}

// Equals two histories
void equal(Node *trie, char* history_a, char* history_b)
{
    Element *elem1 = listElem(trie, history_a);
    Element *elem2 = listElem(trie, history_b);
    if(elem1 == elem2 && elem1 != NULL)
    {
        printf("OK\n");
    }
    else if(elem1 == NULL || elem2 == NULL ||
      (elem1->list->energy == NULL && elem2->list->energy == NULL))
    {
        fprintf( stderr, "ERROR\n");
    }
    else
    {
        merge(elem1, elem2);
        printf("OK\n");
    }
}
