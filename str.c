#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "str.h"
#include "vector.h"

// char *readLine()
// {
//     Vector strChar = vectorDefault;
//
//     char c;
//     do
//     {
//         scanf("%c", &c);
//         pushChar(&strChar, c);
//     } while(c != '\n');
//
//     return (char*)strChar.c;
// }

char **split(char *str)
{
    Vector words = vectorDefault;
    if(strcmp(str,"") == 0)// do przemyślenia
        return words.c;

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

bool correct(char *command)// być może do oddzielnego modułu
{
    return (command[0] != '\n' && command[0] != '#');// do poprawienia
}

char *nextCommand()
{
    size_t size = 16;
    char *input = malloc(size);
    int result;
    do
    {
        result = getline(&input, &size, stdin);
    } while(result != -1 && !correct(input));

    if(result == -1)
    {
        free(input);
        return NULL;
    }
    else
        return input;
}
