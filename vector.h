#ifndef vector_h
#define vector_h

typedef struct
{
    int allocatedMemory;
    int size;
    void *c;
} Vector;

Vector vectorDefault;

// char vector functions
void pushChar(Vector*, char);

void pushCharPtr(Vector*, char*);

#endif // vector_h
