#include "trie.h"

#include <stdlib.h>
#include <string.h>

// Used to initialize new tree
Node trieDefault = {{NULL, NULL, NULL, NULL}, NULL};

int charToInt(char t)
{
    return t - '0';
}

// Adds new history to tree
void insert(Node *t, char *history)
{
    if(strcmp(history, "") == 0)
        return;

    if(t->next[charToInt(*history)] == NULL)
    {
        t->next[charToInt(*history)] = malloc(sizeof(Node));
        if(t->next[charToInt(*history)] == NULL)
        {
            exit(1);
        }
        *t->next[charToInt(*history)] = trieDefault;
        t->next[charToInt(*history)]->energyClass = createList();
    }

    insert(t->next[charToInt(*history)], history+1);
}

// Checks if history is already in tree
bool declared(Node *t, char *history)
{
    if(strcmp(history, "") == 0)
        return true;

    if(t->next[charToInt(*history)] == NULL)
        return false;

    return declared(t->next[charToInt(*history)], history+1);
}

// Deallocates all Nodes in subtree
void freeNode(Node *t)
{
    if(t == NULL)
        return;

    for(int i=0; i<4; i++)
    {
        if(t->next[i] != NULL)
            freeNode(t->next[i]);
        t->next[i] = NULL;
    }
    freeElement(t->energyClass);
    free(t);
}

void del(Node *t, char*history)
{
    // Checking if history length is equal to 1
    if(history[1] == '\0')
    {
        // This funtion deletes everything below this Node
        freeNode( t->next[charToInt(*history)] );
        t->next[charToInt(*history)] = NULL;
        return;
    }

    if(t->next[charToInt(*history)] == NULL)
        return;

    del(t->next[charToInt(*history)], history+1);
}

Element *listElem(Node *t, char *history)
{
    if(strcmp(history, "") == 0)
        return t->energyClass;

    if(t->next[charToInt(*history)] == NULL)
        return NULL;

    return listElem(t->next[charToInt(*history)], history+1);
}
