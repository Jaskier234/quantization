#include <stdlib.h>
#include <stdio.h>
#include "str.h"

char *readLine()
{
    int allocatedMemory = 10;
    char *str = malloc(allocatedMemory);
    int lineSize = 0;

    do
    {
        if( lineSize == allocatedMemory )
        {
            // sprawdzić czy się da
            str = realloc(str, allocatedMemory*2);
            allocatedMemory *= 2;
        }
        scanf("%c", &str[lineSize]);
        lineSize++;
    } while(str[lineSize-1] != '\n');

    return str;
}

char **split(char *str)
{
    int allocatedMemory = 3;
    char **words = malloc(allocatedMemory*sizeof(char**));

    int wordCounter = 0;
    char *lastWordStart = str;
    while(*str != '\n')
    {
        if(*str == ' ')
        {
            if(wordCounter == allocatedMemory)
            {
                allocatedMemory *= 2;
                words = realloc(words, allocatedMemory*sizeof(char**));
            }
            words[wordCounter] = lastWordStart;
            wordCounter++;
            lastWordStart = str+1;
            *str = 0;
        }
        str++;
    }

    *str = 0;

    if(wordCounter == allocatedMemory)
    {
        allocatedMemory *= 2;
        words = realloc(words, allocatedMemory*sizeof(char**));
    }
    if(lastWordStart != str)
    {
        words[wordCounter] = lastWordStart;
        wordCounter++;
    }
    words[wordCounter] = NULL;

    return words;
}
