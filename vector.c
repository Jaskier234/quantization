#include <stdlib.h>
#include "vector.h"

Vector vectorDefault = {0, 0, NULL};

void pushChar(Vector *v, char c)
{
    if(v->size+1 >= v->allocatedMemory)
    {
        v->allocatedMemory = v->allocatedMemory+1*2;
        v->c = realloc(v->c, v->allocatedMemory*sizeof(c));
    }
    ((__typeof__(&c))v->c)[v->size] = c;
    v->size++;
}

void pushCharPtr(Vector *v, char *c)
{
    if(v->size+1 >= v->allocatedMemory)
    {
        v->allocatedMemory = v->allocatedMemory+1*2;
        v->c = realloc(v->c, v->allocatedMemory*sizeof(c));
    }
    ((__typeof__(&c))v->c)[v->size] = c;
    v->size++;
}
/*
char getChar(Vector v, int pos)
{
    return ((char*)v.c)[pos];
}
*/
