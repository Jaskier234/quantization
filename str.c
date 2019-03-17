#include <stdlib.h>
#include <stdio.h>
#include "str.h"
#include "vector.h"

char *readLine()
{
    Vector strChar = vectorDefault;

    char c;
    do
    {
        scanf("%c", &c);
        pushChar(&strChar, c);
    } while(c != '\n');

    return (char*)strChar.c;
}

char **split(char *str)
{
    Vector words = vectorDefault;

    char *lastWordStart = str;
    while(*str != '\n')
    {
        if(*str == ' ')
        {
            pushCharPtr(&words, lastWordStart);
            lastWordStart = str+1;
            *str = 0;
        }
        str++;
    }

    *str = 0;

    if(lastWordStart != str)
    {
        pushCharPtr(&words, lastWordStart);
    }
    pushCharPtr(&words, NULL);

    return (char**)words.c;
}
