#include <stdlib.h>
#include <string.h>
#include "trie.h"
// #include "list.h"

Node trieDefault = {{NULL, NULL, NULL, NULL}, NULL};

int charToInt(char t)
{
    return t - '0';
}

void insert(Node *t, char *string)
{
    // t->declared = true;
    if(strcmp(string, "") == 0)
    {
        return;
    }

    if(t->next[charToInt(*string)] == NULL)
    {
        t->next[charToInt(*string)] = malloc(sizeof(Node)); // sprawdzić czy się da
        *t->next[charToInt(*string)] = trieDefault;
        t->next[charToInt(*string)]->energyClass = createList();
    }

    insert(t->next[charToInt(*string)], string+1);
    // coś tam jeszcze
}

bool declared(Node *t, char *string)
{
    if(strcmp(string, "") == 0)
    {
        return true;
    }

    if(t->next[charToInt(*string)] == NULL)
    {
        return false;
        // t->next[charToInt(*string)] = malloc(sizeof(Node)); // sprawdzić czy się da
    }
    return declared(t->next[charToInt(*string)], string+1);
}

void freeNode(Node *t)
{
    for(int i=0; i<4; i++)
    {
        if(t->next[i] != NULL)
            freeNode(t->next[i]);
        t->next[i] = NULL;// niech zostanie
    }
    freeElement(t->energyClass);
    free(t);
}

void del(Node *t, char*string)
{// nie działa dla pustego stringa :(, ale chyba nie musi
    if(strcmp(string, "0") == 0 ||// rozwiązanie tymczasowe
       strcmp(string, "1") == 0 ||
       strcmp(string, "2") == 0 ||
       strcmp(string, "3") == 0)
    {
        freeNode( t->next[charToInt(*string)] );
        t->next[charToInt(*string)] = NULL;
        return;
    }

    if(t->next[charToInt(*string)] == NULL)
    {
        return;
    }
    del(t->next[charToInt(*string)], string+1);
}

Element *listElem(Node *t, char *string)
{
    if(strcmp(string, "") == 0)
    {
        return t->energyClass;
    }

    if(t->next[charToInt(*string)] == NULL)
    {
        return NULL;
        // t->next[charToInt(*string)] = malloc(sizeof(Node)); // sprawdzić czy się da
    }
    return listElem(t->next[charToInt(*string)], string+1);
}
