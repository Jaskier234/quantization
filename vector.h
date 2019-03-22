#ifndef vector_h
#define vector_h

// Simple vector, used to manage memory

typedef struct
{
    int allocatedMemory;
    int size;
    void *c;
} Vector;

// To initialize
Vector vectorDefault;

// char vector functions
void pushChar(Vector*, char);

void pushCharPtr(Vector*, char*);

#endif // vector_h
